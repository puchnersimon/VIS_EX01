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

/**
 * TCP Ipv4 Client
 * This client can communicate with an Ipv4 Server (class TCP_v4_Echo_server).
 */
class TCP_v4_client {
public:
    /**
     * Client Socket
     */
    SOCKET mCommSocket;

    /**
     * Constructor
     */
    TCP_v4_client();

    /**
     * Destructor.
     */
    virtual ~TCP_v4_client();

    /**
     * Opens methods in right order.
     * @param _argv is necessary for connecting to a server.
     */
    void InitializeSocket(char **_argv);

    /**
     * Creates the socket and exits with -1 if this procedure fails.
     */
    //create-Socket
    void createSocket();

    /**
     * Starts a connection with a server. If this fails, the programm exits with -1.
     * @param _argv contains port.
     */
    //connect-Server
    void connectServer(char **_argv);

    /**
     * Receives and prints message which was previously sent, in case receiving works. If not it exits with -1.
     */
    //recv
    void recvMessage();

    /**
     * Reads message from console and sends it to the server.
     * Checks if the message was "shutdown" or "quit" and exits if one of them is true.
     * Starts receiving in the end.
     */
    //send
    void sendMessage();

};


#endif //VIS_EX01_TCP_V4_CLIENT_HPP
