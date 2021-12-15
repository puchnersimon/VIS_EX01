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

/**
 * TCP Envi server
 * This is the envi server, which offers three different values: light, air and noise.
 * Those values are simulated by random values.
 */
class TCP_Envi_server {
public:
    SOCKET mServerSocket;
    SOCKET mCommSocket;

    /**
     * Sets mServersocket and mCommSocket to 0.
     */
    //constructor
    TCP_Envi_server();

    /**
     * Deletes allocated memory
     */
    //destructor
    virtual ~TCP_Envi_server();

    /**
     * Opens methods in correct order.
     * @param _argv is necessary for binding method.
     */
    //initialize-methode
    //socketHandler
    void InitializeSocket(char **_argv);

    /**
     * creates the socket
     * checks if an error occurs and exits with -1.
     */
    //create-Socket
    void createSocket();

    /**
     * Binds the socket to a port and a network address of the machine.
     * @param _argv contains port.
     */
    //bind-Socket
    void bindSocket(char **_argv);

    //setSocketOptions
    //void setSocketOptions();

    /**
     * Shifts the socket into the listen mode - waits for client.
     * If it fails, the methode exits with -1.
     */
    //listen
    void listenSocket();

    /**
     *  Waits for clients to connect. If it fails, the methode exits with -1.
     */
    //accept-Client
    void acceptClient();

    /**
     * Is necessary to make threads possible. Receives message from a client and checks if it is correct.
     * Returns -1 if not. Then checks if the message is "quit", which quits the connection with a client,
     * or "shutdown", which closes the socket.
     * If those two comparisons are wrong it checks which command has been sent and answers with the corresponding
     * light, noise or air value. Or it sends either a information on which values are available or even sends all of them.
     * @param _parameter - contains server- and commSocket
     * @return
     */
    //recv - with thread
    static void *clientCommunicaton(void *_parameter);


};


#endif //VIS_EX01_TCP_ENVI_SERVER_HPP
