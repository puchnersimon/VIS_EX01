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


// ---
#include <pcap/socket.h>

#define BUFFER_SIZE 1024


#include "UDP_server.hpp"

UDP_server::UDP_server() {
    mServerSocket = 0;
}

UDP_server::~UDP_server() {

}

void UDP_server::InitializeSocket(char **_argv) {
    createSocket();
    bindSocket(_argv);
    recvFromMessage(_argv);
}

void UDP_server::createSocket() {
    mServerSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    //errorhandling
    if (mServerSocket == -1) {
        exit(-1);
    }
}

void UDP_server::bindSocket(char **_argv) {
    int port = atoi(_argv[1]);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int rVal_bind = ::bind(mServerSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));
    //errorhandling - if serversocket cannot created, program exits with errorcode: -1
    if (rVal_bind == -1) {
        exit(-1);
    }
}

void UDP_server::recvFromMessage(char **_argv) {
    while (1) {

        char msg_recv[BUFFER_SIZE];
        //empty char array
        memset(msg_recv, 0, sizeof(msg_recv));

        sockaddr_in from;
        socklen_t fromSize = sizeof(from);
        int rVal_recv = recvfrom(mServerSocket, msg_recv, BUFFER_SIZE, 0, (sockaddr *) &from, &fromSize);
        if (rVal_recv == -1) {
            std::cout << "Error!";
            exit(0);
        }

        //quit client - compare char array
        char quit_string[BUFFER_SIZE] = "quit";
        int quit_val = strcmp(quit_string, msg_recv);

        //shutdown server - compare char array
        char shutdown_string[BUFFER_SIZE] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_recv);

        if (shutdown_val == 0) {
            std::cout << "Server & Client shutdown!\n";
            //close socket
            close(mServerSocket);
            exit(0);
            //quit only client
        } else if (quit_val == 0) {
            std::cout << "Client quit!\n";
            memset(msg_recv, 0, sizeof(msg_recv));

            //wait for new client - wait as long a new client will connect to server
            //acceptClient();
            std::cout << "Client online!\n";
            //server->mCommSocket = accept(server->mServerSocket, (sockaddr *) &clientAddr, &clientAddrSize);
            if (mServerSocket == -1) {
                std::cout << "Error!";
                exit(0);
            }

        } else {
            //print the recv message
            std::cout << "message received: " << msg_recv << "\n";

            //send echo
            sendToMessage(msg_recv, _argv, from);
        }
    }
}

void UDP_server::sendToMessage(char *msg_recv, char **_argv, sockaddr_in _from) {
    char *msg_send = msg_recv;
    int msg_sendSize = strlen(msg_send);

    int toSize = sizeof(_from);

    int rVal_send = sendto(mServerSocket, msg_send, msg_sendSize, 0, (sockaddr *) &_from, toSize);
    if (rVal_send == -1) {
        std::cout << "Error!";
        exit(-1);
    }
}
