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
 * @param mCommSocket socket variable for client to connect and communicate with serversocket
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
     * @param _argv hands over the port and the ip address
     */
    void InitializeSocket(char **_argv);

    /**
     * creates the socket
     * checks if an error occurs and exits with -1.
     */
    //create-Socket
    void createSocket();

    /**
     * connects to a server, with the right port and address.
     * Those two values are saved in _argv. If the connect process fails, we exit with -1
     * @param _argv hand over port and ip address
     */
    //connect-Server
    void connectServer(char **_argv);

    /**
     * sends "getSensortypes()" to the server, in order to get a list of the types available
     * @param _msg is the message "getSensortypes()"
     */
    void getSensortypes(char _msg[]);

    /**
     * sends the message if it was one of the three available types
     * @param _msg is the message "getSensor(type)"
     */
    void getSensor(char _msg[]);

    /**
     * sends message to get all sensor dates
     * @param _msg is the message "getAllSensors()"
     */
    void getAllSensors(char _msg[]);


    //recv
    /**
     * Receives the data from the server.
     * Exits with 0 if the receiving procedure fails
     */
    void recvMessage();

    //send
    /**
     * Reads input from console and checks that input. If input is "quit" or "shutdown",
     * this message will be sent and client exits afterwards.
     * Else it checks whether it is a correct command or not and opens the associated method.
     */
    void sendMessage();


};


#endif //VIS_EX01_TCP_ENVI_CLIENT_HPP
