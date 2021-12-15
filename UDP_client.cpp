//
// Created by Simon Puchner on 09.12.21.
//
#include <iostream> // cout, cin
#include <sys/socket.h> // socket, bind, listen, accept
#include <netinet/in.h> // IPPROTO_TCP, sockaddr_in,
// htons/ntohs, INADDR_ANY
#include <unistd.h> // close
#include <arpa/inet.h> // inet_ntop/inet_atop
#include <string.h> // strlen
#include <semaphore.h> // sem_init
#include <pcap/socket.h>
#define BUFFER_SIZE 1024


#include "UDP_client.hpp"

UDP_client::UDP_client() {
    mCommSocket = 0;
}

UDP_client::~UDP_client() {

}

void UDP_client::InitializeSocket(char **_argv) {
    createSocket();
    sendToMessage(_argv);
}

void UDP_client::createSocket() {
    mCommSocket = socket(AF_INET, SOCK_DGRAM, 0);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }
}

void UDP_client::sendToMessage(char **_argv) {
    while (1) {
        char msg_send[BUFFER_SIZE];
        std::cout << "enter a message: ";
        std::cin.getline(msg_send, BUFFER_SIZE);
        int msg_sendSize = strlen(msg_send);

        int port = atoi(_argv[1]);
        sockaddr_in toAddr;
        toAddr.sin_family       = AF_INET;
        toAddr.sin_port         = htons(port);
        toAddr.sin_addr.s_addr  = inet_addr(_argv[2]);
        int toSize              = sizeof (toAddr);
        //sendto(mCommSocket, msg_send, msg_sendSize, 0, (sockaddr*) &toAddr, toSize);


        //shutdown server
        char shutdown_string[] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_send);

        if (shutdown_val == 0) {
            int rVal_send = sendto(mCommSocket, msg_send, msg_sendSize, 0, (sockaddr*) &toAddr, toSize);
            if (rVal_send == -1) {
                exit(-1);
            }

            //empty char array
            memset(msg_send, 0, sizeof(msg_send));

            std::cout << "Server & Client shutdown!";
            //close socket
            close(mCommSocket);
            exit(0);
        }

        //quit client
        char quit_string[] = "quit";
        int quit_val = strcmp(quit_string, msg_send);

        if (quit_val == 0) {
            int rVal_send = sendto(mCommSocket, msg_send, msg_sendSize, 0, (sockaddr*) &toAddr, toSize);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }

            //empty char array
            memset(msg_send, 0, sizeof(msg_send));

            std::cout << "Client quit!";
            //close socket
            close(mCommSocket);
            exit(0);
        }


        //send message if message is not "quit" or "shutdown"
        int rVal_send = sendto(mCommSocket, msg_send, msg_sendSize, 0, (sockaddr *) &toAddr, toSize);
        if (rVal_send == -1) {
            std::cout << "Error!";
            exit(0);
        }

        //empty char array
        memset(msg_send, 0, sizeof(msg_send));


        //recv
        recvFromMessage();
    }
}

void UDP_client::recvFromMessage() {
    char msg_recv[BUFFER_SIZE];
    memset(msg_recv, 0, sizeof(msg_recv));

    sockaddr_in from;
    socklen_t fromSize        = sizeof (from);
    int rVal_recv = recvfrom(mCommSocket, msg_recv, BUFFER_SIZE, 0, (sockaddr*) &from, &fromSize);
    if (rVal_recv == -1) {
        std::cout << "Error!";
        exit(0);
    }
    std::cout << msg_recv;
    std::cout << "\n";
}