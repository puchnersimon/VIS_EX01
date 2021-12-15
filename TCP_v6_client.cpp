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


#include "TCP_v6_client.hpp"

TCP_v6_client::TCP_v6_client() {
    mCommSocket = 0;
}

TCP_v6_client::~TCP_v6_client() {

}

void TCP_v6_client::InitializeSocket(char **_argv) {
    createSocket();
    connectServer(_argv);
    sendMessage();
}

void TCP_v6_client::createSocket() {
    mCommSocket = socket(AF_INET6, SOCK_STREAM, 0);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }
}

void TCP_v6_client::connectServer(char **_argv) {
    int port = atoi(_argv[1]);
    sockaddr_in6 serverAddr;
    serverAddr.sin6_family      = AF_INET6;
    serverAddr.sin6_flowinfo    = 0;
    serverAddr.sin6_port        = htons(port);
    serverAddr.sin6_scope_id    = 0;
    inet_pton(AF_INET6, _argv[3], &(serverAddr.sin6_addr));

    int retVal_connect = connect(mCommSocket, (sockaddr*) & serverAddr, sizeof(serverAddr));
    //errorhandling
    if (retVal_connect == -1) {
        exit(-1);
    }
}

void TCP_v6_client::sendMessage() {
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

void TCP_v6_client::recvMessage() {
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
