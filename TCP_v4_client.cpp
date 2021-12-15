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

#include "TCP_v4_client.hpp"

TCP_v4_client::TCP_v4_client() {
    mCommSocket = 0;
}

TCP_v4_client::~TCP_v4_client() {

}

void TCP_v4_client::InitializeSocket(char **_argv) {
    createSocket();
    connectServer(_argv);
    sendMessage();

}

void TCP_v4_client::createSocket() {
    mCommSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }
}

void TCP_v4_client::connectServer(char **_argv) {
    int port = atoi(_argv[1]);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(_argv[2]);

    int rVal_connect = connect(mCommSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));
    //errorhandling
    if (rVal_connect == -1) {
        exit(-1);
    }
}

void TCP_v4_client::sendMessage() {
    while (1) {
        char msg_send[BUFFER_SIZE];
        std::cout << "enter a message: ";
        std::cin.getline(msg_send, BUFFER_SIZE);
        int msg_sendSize = strlen(msg_send);


        //shutdown server
        char shutdown_string[] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_send);

        if (shutdown_val == 0) {
            int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
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
            int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
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
        int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
        if (rVal_send == -1) {
            std::cout << "Error!";
            exit(0);
        }

        //empty char array
        memset(msg_send, 0, sizeof(msg_send));



        //recv
        recvMessage();

    }
}

void TCP_v4_client::recvMessage() {
    char msg_recv[BUFFER_SIZE];
    memset(msg_recv, 0, sizeof(msg_recv));
    int rVal_recv = recv(mCommSocket, msg_recv, BUFFER_SIZE, 0);
    if (rVal_recv == -1) {
        std::cout << "Error!";
        exit(0);
    }
    std::cout << msg_recv;
    std::cout << "\n";
}