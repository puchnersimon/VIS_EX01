//
// Created by Simon Puchner on 09.12.21.
//

#ifndef VIS_EX01_TCP_V6_CLIENT_HPP
#define VIS_EX01_TCP_V6_CLIENT_HPP


class TCP_v6_client {
public:
    SOCKET mCommSocket;

    TCP_v6_client();

    virtual ~TCP_v6_client();

    void InitializeSocket(char **_argv);

    //create-Socket
    void createSocket();

    //connect-Server
    void connectServer(char **_argv);

    //recv
    void recvMessage();

    //send
    void sendMessage();

};


#endif //VIS_EX01_TCP_V6_CLIENT_HPP
