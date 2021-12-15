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



#ifndef VIS_EX01_UDP_CLIENT_HPP
#define VIS_EX01_UDP_CLIENT_HPP


class UDP_client {
public:
    SOCKET mCommSocket;

    UDP_client();

    virtual ~UDP_client();

    void InitializeSocket(char **_argv);

    //create-Socket
    void createSocket();

    //recv
    void recvFromMessage();

    //send
    void sendToMessage(char **_argv);

};


#endif //VIS_EX01_UDP_CLIENT_HPP
