//
// Created by Simon Puchner on 09.12.21.
//

#ifndef VIS_EX01_TCP_V6_CLIENT_HPP
#define VIS_EX01_TCP_V6_CLIENT_HPP

/**
 * TCP Ipv6 Client
 * This client can communicate with an Ipv6 Server (class TCP_v6_server).
 */
class TCP_v6_client {
public:
    /**
     * Communication Socket
     */
    SOCKET mCommSocket;

    /**
     * Constructor
     */
    TCP_v6_client();

    /**
     * Destructor
     */
    virtual ~TCP_v6_client();

    /**
     * Opens method in right order.
     * @param _argv necessary for connecting.
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


#endif //VIS_EX01_TCP_V6_CLIENT_HPP
