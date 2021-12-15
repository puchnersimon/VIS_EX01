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

/**
 * UDP Server
 * Gets messages from UDP clients (class UDP_client) and sends them back
 */
class UDP_server {
public:
    /**
     * Server Socket
     */
    SOCKET mServerSocket;

    /**
     * Constructor
     */
    //constructor
    UDP_server();

    /**
     * Destructor
     */
    //destructor
    virtual ~UDP_server();

    /**
     * Starts methods in correct order
     * @param _argv is necessary for binding and receiving method
     */
    //initialize-methode
    //socketHandler
    void InitializeSocket(char **_argv);

    /**
     * Creates the socket and exits with -1 if this fails.
     */
    //create-Socket
    void createSocket();

    /**
     * Binds the socket to a port and a network address of the machine.
     * @param _argv contains port.
     */
    //bind-Socket
    void bindSocket(char **_argv);

    /**
     * Receives message and checks if message is "quit" or "shutdown". Shutdown closes the socket, whereas
     * quit only closes the connection with a specific client.
     * If none of those two applies, the server prints the message and opens the send method with
     * received the message
     * @param _argv necessary for sending method
     */
    //recv
    void recvFromMessage(char **_argv);

    /**
     * Sends received message back to the client. Exits with -1 if this fails.
     * @param msg_recv received message from client
     * @param _argv parameter
     * @param _from address which sent the message
     */
    //send
    void sendToMessage(char *msg_recv, char **_argv, sockaddr_in _from);

};


#endif //VIS_EX01_UDP_SERVER_HPP
