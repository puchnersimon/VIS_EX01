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

// ---

#ifndef VIS_EX01_TCP_SERVER_HPP
#define VIS_EX01_TCP_SERVER_HPP

/**
 * TCP Ipv4 Echo Server
 * Receives messages from clients and sends them back.
 */
class TCP_v4_Echo_server {
public:
    /**
     * Server Socket
     */
    SOCKET mServerSocket;
    /**
     * Communication Socket
     */
    SOCKET mCommSocket;

    /**
     * Constructor
     */
    //constructor
    TCP_v4_Echo_server();

    /**
     * Destructor
     */
    //destructor
    virtual ~TCP_v4_Echo_server();

    /**
     * Starts methods in the right order
     * @param _argv necessary for binding method.
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

    //setSocketOptions
    //void setSocketOptions();

    /**
     * Shifts the socket into the listen mode - waits for client.
     * If it fails, the methode exits with -1.
     */
    //listen
    void listenSocket();

    /**
     * Accepts the client and starts thread for mutual use. If thread ends accept is called again.
     */
    //accept-Client
    void acceptClient();

    /**
     * Is necessary to make threads possible. Receives message from a client and checks if it is correct.
     * Returns -1 if not. Then checks if the message is "quit", which quits the connection with a client,
     * or "shutdown", which closes the socket.
     * If those two comparisons are wrong it prints the message from the client. Repeats that process if client did not quited or shut both itself and server down.
     * @param _parameter - contains server- and commSocket
     * @return void
     */
    //recv - with thread
    static void* clientCommunicaton(void* _parameter);

    //send
    //void sendMessage(char *msg_recv);
};


#endif //VIS_EX01_TCP_SERVER_HPP
