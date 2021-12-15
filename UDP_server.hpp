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




#ifndef VIS_EX01_UDP_SERVER_HPP
#define VIS_EX01_UDP_SERVER_HPP


class UDP_server {
public:
    SOCKET mServerSocket;


    //constructor
    UDP_server();

    //destructor
    virtual ~UDP_server();

    //initialize-methode
    //socketHandler
    void InitializeSocket(char **_argv);

//private:
    //create-Socket
    void createSocket();

    //bind-Socket
    void bindSocket(char **_argv);

    //recv
    void recvFromMessage(char **_argv);

    //send
    void sendToMessage(char *msg_recv, char **_argv, sockaddr_in _from);

};


#endif //VIS_EX01_UDP_SERVER_HPP
