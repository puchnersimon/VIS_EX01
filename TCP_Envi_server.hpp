//
// Created by Simon Puchner on 10.12.21.
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

// ---

#ifndef VIS_EX01_TCP_ENVI_SERVER_HPP
#define VIS_EX01_TCP_ENVI_SERVER_HPP


class TCP_Envi_server {
public:
    SOCKET mServerSocket;
    SOCKET mCommSocket;


    //constructor
    TCP_Envi_server();

    //destructor
    virtual ~TCP_Envi_server();

    //initialize-methode
    //socketHandler
    void InitializeSocket(char **_argv);

//private:
    //create-Socket
    void createSocket();

    //bind-Socket
    void bindSocket(char **_argv);

    //setSocketOptions
    //void setSocketOptions();

    //listen
    void listenSocket();

    //accept-Client
    void acceptClient();

    //recv - with thread
    static void* clientCommunicaton(void* _parameter);


};


#endif //VIS_EX01_TCP_ENVI_SERVER_HPP
