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



#ifndef VIS_EX01_TCP_V6_ECHO_SERVER_HPP
#define VIS_EX01_TCP_V6_ECHO_SERVER_HPP


class TCP_v6_Echo_server {
public:
    SOCKET mServerSocket;
    SOCKET mCommSocket;


    //constructor
    TCP_v6_Echo_server();

    //destructor
    virtual ~TCP_v6_Echo_server();

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

    //listen-Socket
    void listenSocket();

    //accept-Client
    void acceptClient();

    //recv
    static void* clientCommunication(void* _parameter);

    //send
    void sendMessage(char *msg_recv);

};


#endif //VIS_EX01_TCP_V6_ECHO_SERVER_HPP
