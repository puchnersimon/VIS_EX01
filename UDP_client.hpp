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

/**
 * UDP Client
 * Can communicate with an UDP Server
 */
class UDP_client {
public:
    /**
     * Communication Socket
     */
    SOCKET mCommSocket;

    /**
     * Constructor
     */
    UDP_client();

    /**
     * Deestructor
     */
    virtual ~UDP_client();

    /**
     * Calls createSocket() and sendToMessage() methods.
     * @param _argv necessary for sending method
     */
    void InitializeSocket(char **_argv);

    /**
     * creates the socket
     * checks if an error occurs and exits with -1 if so.
     */
    //create-Socket
    void createSocket();

    /**
     * Receives and prints out message if receiving procedure works.
     * Exits with -1 if not.
     */
    //recv
    void recvFromMessage();

    /**
     * Reads message from console and checks it.
     * @param _argv
     */
    //send
    void sendToMessage(char **_argv);

};


#endif //VIS_EX01_UDP_CLIENT_HPP
