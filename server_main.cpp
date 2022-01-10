//
// Created by Simon Puchner on 01.12.21.
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

#include "TCP_v4_Echo_server.hpp"
#include "TCP_v6_Echo_server.hpp"
#include "UDP_server.hpp"
#include "TCP_Envi_server.hpp"
#include "TCP_HTTP_server.hpp"

#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#define BUFFER_SIZE 1024

using namespace std;


/**
 * main class for the servers - it´s possible to choose one of the servers with there enabled protocol
 * @param _argc programparameter
 * @param _argv value for port(index: 1)
 * @return
 */
int main(int _argc, char **_argv) {
    //runs server aslong value gets false
    //bool server_run = true;


    //2.1a
    //choose server

    cout << "\n C++ Server Menu: \n---------------\n 1. Start TCP v4 Echo Server\n 2. Start TCP v6 Echo Server\n 3. Start UDP    Echo Server\n 4. Start TCP    HTTP Server\n 5. Start TCP    Envi Server\n 6. EXIT\n---------------\n Choose server to start: ";
    char type_char[BUFFER_SIZE];
    cin.getline(type_char, BUFFER_SIZE);
    int type = atoi(type_char);

    /*
    if (type == 1) {
        TCP_v4_Echo_server *server = new TCP_v4_Echo_server();
        server->InitializeSocket(_argv);
    }
    if (type == 2) {
        TCP_v6_Echo_server *serverv6 = new TCP_v6_Echo_server();
        serverv6->InitializeSocket(_argv);
    }
    if (type == 3) {

    }

    if (type == 6) {
        cout << "Exit!";
    }
    if (type > 6) {
        cout << "No Valid input";
        return 0;
    }
*/

    switch (type) {
        case 1: {
            TCP_v4_Echo_server server = TCP_v4_Echo_server();
            server.InitializeSocket(_argv);
            break;
        }
        case 2: {
            TCP_v6_Echo_server serverv6 = TCP_v6_Echo_server();
            serverv6.InitializeSocket(_argv);
            break;
        }
        case 3: {
            UDP_server serverudp = UDP_server();
            serverudp.InitializeSocket(_argv);
            break;
        }
        case 4: {
            TCP_HTTP_server httpServer = TCP_HTTP_server();
            httpServer.InitializeSocket(_argv);
            break;
        }
        case 5: {
            TCP_Envi_server serverEnvi = TCP_Envi_server();
            serverEnvi.InitializeSocket(_argv);
            break;
        }
        default:
            cout << "No valid input!";
            return 0;
    }

    /*
    TCP_v4_Echo_server *server = new TCP_v4_Echo_server();
    server->InitializeSocket(_argv);
    server->recvMessage();



    // --- 1.1 - 1.3 ---

    /*

    //1.1a
    //create socket
    SOCKET mServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mServerSocket == -1) {
        std::cout << "Error!";
        return 0;
    }


    //bind
    int port = atoi(_argv[1]);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int rVal_bind = ::bind(mServerSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));
    if (rVal_bind == -1) {
        std::cout << "Error!";
        return 0;
    }


    //listen
    int rVal_listen = listen(mServerSocket, 10);
    if (rVal_listen == -1) {
        std::cout << "Error!";
        return 0;
    }

    //accept
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    SOCKET mCommSocket = accept(mServerSocket, (sockaddr *) &clientAddr, &clientAddrSize);
    if (mCommSocket == -1) {
        std::cout << "Error!";
        return 0;
    }

    //1.1b --> changed values in "Edit Configurations"
    cout << "--- 1.1b --- \n";
    cout << _argv[1] << "\n";

    //convert ip adress in readable format and print
    char *ip = inet_ntoa(clientAddr.sin_addr);
    cout << "converted ip: " << ip << "\n";
    cout << "communication port from client: " << clientAddr.sin_port << "\n\n";

     */

    //1.1c
    //recv
    cout << "--- 1.1c --- \n";

    /*

    while (server_run == true) {

        char msg_recv[BUFFER_SIZE];
        //empty char array
        memset(msg_recv, 0, sizeof(msg_recv));

        int rVal_recv = recv(server->mCommSocket, msg_recv, BUFFER_SIZE, 0);
        if (rVal_recv == -1) {
            std::cout << "Error!";
            return 0;
        }

        //quit client - compare char array
        char quit_string[BUFFER_SIZE] = "quit";
        int quit_val = strcmp(quit_string, msg_recv);

        //shutdown server - compare char array
        char shutdown_string[BUFFER_SIZE] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_recv);

        if (shutdown_val == 0) {
            cout << "Server & Client shutdown!\n";
            return 0;
            //quit only client
        } else if (quit_val == 0) {
            cout << "Client quit!\n";
            memset(msg_recv, 0, sizeof(msg_recv));

            //wait for new client - wait as long a new client will connect to server
            server->acceptClient();
            cout << "Client online!\n";
            //server->mCommSocket = accept(server->mServerSocket, (sockaddr *) &clientAddr, &clientAddrSize);
            if (server->mCommSocket == -1) {
                std::cout << "Error!";
                return 0;
            }

        } else {
            //print the recv message
            std::cout << "message recved: " << msg_recv << "\n";


            //send ACK to client
            // 2.1 --> change "ACK" to "revc message"
            //send "ECHO"
            char *msg_send = msg_recv;
            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(server->mCommSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                return 0;
            }
        }

    }



    */


    /*

    //recv
    char msg[BUFFER_SIZE];
    int rVal_recv = recv(mCommSocket, msg, BUFFER_SIZE, 0);
    if (rVal_recv == -1) {
        std::cout << "Error!";
        return 0;
    }

    //send
    char* msg_send       = "Send from Server succeded!";
    int msg_sendSize     = strlen(msg_send);
    int rVal_send        = send(mCommSocket, msg_send, msg_sendSize, 0);
    if (rVal_send == -1) {
        std::cout << "Error!";
        return 0;
    }

    //close
    int rVal_close = close(mCommSocket);
    if (rVal_close == -1) {
        std::cout << "Error!";
        return 0;
    }
     */

    cout << "all went fine!";
}

#endif