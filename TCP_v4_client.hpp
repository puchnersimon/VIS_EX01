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



#ifndef VIS_EX01_TCP_V4_CLIENT_HPP
#define VIS_EX01_TCP_V4_CLIENT_HPP


class TCP_v4_client {
public:
    SOCKET mCommSocket;

    TCP_v4_client();

    virtual ~TCP_v4_client();

    void InitializeSocket(char **_argv);

    //create-Socket
    void createSocket();

    //connect-Server
    void connectServer(char **_argv);

    //recv
    void recvMessage();

    //send
    void sendMessage();

};


#endif //VIS_EX01_TCP_V4_CLIENT_HPP
