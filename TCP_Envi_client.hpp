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
#include <pcap/socket.h>



#ifndef VIS_EX01_TCP_ENVI_CLIENT_HPP
#define VIS_EX01_TCP_ENVI_CLIENT_HPP

/**
 * TCP Environment Client
 * this client can communicate with the TCP_envi_server
 * the client uses specific commands(shown by starting client) to get values from different sensortypes
 * @param mCommSocket socketvariable for client to connect and communicate with serversocket
 */
class TCP_Envi_client {
public:
    SOCKET mCommSocket;

    /**
     * constructor for envi_client
     * sets the socket to 0
     */
    TCP_Envi_client();

    /**
     * destructor
     * not used
     */
    virtual ~TCP_Envi_client();

    /**
     * initialize the client
     * calls createSocket, connectServer, sendMessage methods
     * @param _argv hands over the port and the ip adress
     */
    void InitializeSocket(char **_argv);

    /**
     * creates the socket
     */
    //create-Socket
    void createSocket();

    //connect-Server
    void connectServer(char **_argv);

    void getSensortypes(char _msg[]);

    void getSensor(char _msg[]);

    void getAllSensors(char _msg[]);


    //recv
    void recvMessage();

    //send
    void sendMessage();


};


#endif //VIS_EX01_TCP_ENVI_CLIENT_HPP
