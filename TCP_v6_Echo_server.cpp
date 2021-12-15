//
// Created by Simon Puchner on 09.12.21.
//
#define BUFFER_SIZE 1024

#include "TCP_v6_Echo_server.hpp"

struct socketParam {
    int mCommSocket;
    int mServerSocket;
    sockaddr_in6 saddr;

};


TCP_v6_Echo_server::TCP_v6_Echo_server() {
    mServerSocket = 0;
    mCommSocket = 0;
}

TCP_v6_Echo_server::~TCP_v6_Echo_server() {

}

void TCP_v6_Echo_server::InitializeSocket(char **_argv) {
    createSocket();
    bindSocket(_argv);
    listenSocket();
    acceptClient();
    //recvMessage();
}

void TCP_v6_Echo_server::createSocket() {
    mServerSocket = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);

    //errorhandling - if serversocket cannot created, program exits with errorcode: -1
    if (mServerSocket == -1) {
        exit(-1);
    }
}

void TCP_v6_Echo_server::bindSocket(char **_argv) {

    int port = atoi(_argv[1]);
    sockaddr_in6 serverAddr;
    serverAddr.sin6_family = AF_INET6;
    serverAddr.sin6_flowinfo = 0;
    serverAddr.sin6_port = htons(port);
    serverAddr.sin6_scope_id = 0;
    serverAddr.sin6_addr = IN6ADDR_ANY_INIT;

    int rVal_bind = ::bind(mServerSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));

    //errorhandling - if serversocket cannot created, program exits with errorcode: -1
    if (rVal_bind == -1) {
        exit(-1);
    }
}

void TCP_v6_Echo_server::listenSocket() {
    int rVal_listen = listen(mServerSocket, 10);
    //errorhandling
    if (rVal_listen == -1) {
        exit(-1);
    }
}

void TCP_v6_Echo_server::acceptClient() {
    sockaddr_in6 clientAddr;
    socklen_t clientAddrSize = sizeof(sockaddr_in6);
    mCommSocket = accept(mServerSocket, (sockaddr *) &clientAddr, &clientAddrSize);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }

    //create thread
    socketParam* parameter = new socketParam();
    parameter->mCommSocket = mCommSocket;
    parameter->mServerSocket = mServerSocket;
    parameter->saddr = clientAddr;
    pthread_t threadID;
    int rVal = pthread_create(&threadID, NULL, clientCommunication, (void*) parameter);
    //errohandling
    if (rVal != 0) {
        exit(-1);
    }
    acceptClient();
}

void *TCP_v6_Echo_server::clientCommunication(void *_parameter) {
    //for thread
    socketParam* p = (socketParam*) _parameter;
    int commSocket = p->mCommSocket;
    int serverSocket = p->mServerSocket;
    sockaddr_in6 clientAddr = p->saddr;

    while (1) {

        char msg_recv[BUFFER_SIZE];
        //empty char array
        memset(msg_recv, 0, sizeof(msg_recv));

        int rVal_recv = recv(commSocket, msg_recv, BUFFER_SIZE, 0);
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
            close(commSocket);
            close(serverSocket);
            //quit only client
        } else if (quit_val == 0) {
            std::cout << "Client quit!\n";
            memset(msg_recv, 0, sizeof(msg_recv));

            //wait for new client - wait as long a new client will connect to server
            //acceptClient();
            break;
        } else {
            //print the recv message
            std::cout << "message recved: " << msg_recv << "\n";

            //send echo
            //sendMessage(msg_recv);
            char *msg_send = msg_recv;
            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(commSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }
        }
    }

}

/*
void TCP_v6_Echo_server::sendMessage(char *msg_recv) {
    char *msg_send = msg_recv;
    int msg_sendSize = strlen(msg_send);
    int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
    if (rVal_send == -1) {
        std::cout << "Error!";
        exit(0);
    }
}
 */