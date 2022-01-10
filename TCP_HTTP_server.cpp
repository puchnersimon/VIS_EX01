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
#include <string>
#include <algorithm>
#include <regex>

// ---
#include <pcap/socket.h>

#define BUFFER_SIZE 1024


#include "TCP_HTTP_server.hpp"

struct socketParam {
    int mCommSocket;
    int mServerSocket;
    sockaddr_in saddr;
};


//constructor
TCP_HTTP_server::TCP_HTTP_server() {
    mServerSocket = 0;
    mCommSocket = 0;
}

//destructor
TCP_HTTP_server::~TCP_HTTP_server() {

}

//initialize-methode
void TCP_HTTP_server::InitializeSocket(char **_argv) {
    createSocket();
    bindSocket(_argv);
    listenSocket();
    acceptClient();
}

//create-Socket
void TCP_HTTP_server::createSocket() {

    mServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //errorhandling - if serversocket cannot created, program exits with errorcode: -1
    if (mServerSocket == -1) {
        exit(-1);
    }
}

//bind-Socket
void TCP_HTTP_server::bindSocket(char **_argv) {

    int port = 80;
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

//setSocketOptions
//void TCP_v4_Echo_server::setSocketOptions() {}



//listen-Socket
void TCP_HTTP_server::listenSocket() {

    int rVal_listen = listen(mServerSocket, 10);
    if (rVal_listen == -1) {
        exit(-1);
    }
}

//accept-Client
void TCP_HTTP_server::acceptClient() {
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    mCommSocket = accept(mServerSocket, (sockaddr *) &clientAddr, &clientAddrSize);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }

    //create parameter for thread
    socketParam *parameter = new socketParam();
    parameter->mCommSocket = mCommSocket;
    parameter->mServerSocket = mServerSocket;
    parameter->saddr = clientAddr;

    //create thread
    pthread_t threadID;
    int rVal = pthread_create(&threadID, NULL, clientCommunicaton, (void *) parameter);
    //errorhandling
    if (rVal != 0) {
        exit(-1);
    }
    acceptClient();
}

void *TCP_HTTP_server::clientCommunicaton(void *_parameter) {
    //for thread
    socketParam *p = (socketParam *) _parameter;
    int commSocket = p->mCommSocket;
    int serverSocket = p->mServerSocket;
    sockaddr_in clientAddr = p->saddr;


    while (1) {
        char msg_recv[BUFFER_SIZE];
        //empty char array
        memset(msg_recv, 0, sizeof(msg_recv));

        int rVal_recv = recv(commSocket, msg_recv, BUFFER_SIZE, 0);
        if (rVal_recv == -1) {
            std::cout << "Error!";
            exit(0);
        }

        //convert char-array into string
        std::string string = "";
        for (int i = 0; i < BUFFER_SIZE; i++) {
            string += msg_recv[i];
        }
        // use <br> instead of \n
        std::regex newlines_re("\n+");
        auto result = std::regex_replace(string, newlines_re, "<br>");
        memset(msg_recv, 0, sizeof(msg_recv));
        strcpy(msg_recv, result.c_str());


        //print the recv message
        std::cout << "\n\nmessage recved: \n\n" << msg_recv << "\n";

        //send echo
        //sendMessage(msg_recv);
        char msg_send[BUFFER_SIZE] = "HTTP/1.1 200 OK\nContent-Type: text/html;charset=ISO-8859-1\nContent-Length: ";
        char content[BUFFER_SIZE] = "\n\n<html>\n<head>\n<title>HTTP-ECHO</title>\n</head>\n<body><h1>BROWSER REQUEST</h1><br>";
        strcat(content, msg_recv);
        char *cont = "</body>\n</html>";
        strcat(content, cont);

        int msg_sendSize = strlen(content) - 2;
        std::string s = std::to_string(msg_sendSize);
        char contentLength[BUFFER_SIZE];
        strcpy(contentLength, s.c_str());

        strcat(msg_send, contentLength);
        strcat(msg_send,content);

        int msg_Size = strlen(msg_send);
        std::cout << msg_send;
        int rVal_send = send(commSocket, msg_send, msg_Size, 0);
        if (rVal_send == -1) {
            std::cout << "Error!";
            exit(0);
        }
    }
}