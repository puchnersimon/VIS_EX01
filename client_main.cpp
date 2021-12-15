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
#include <pcap/socket.h>


#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H

#define BUFFER_SIZE 1024

#include "TCP_v4_client.hpp"
#include "TCP_v6_client.hpp"
#include "UDP_client.hpp"
#include "TCP_Envi_client.hpp"

using namespace std;

/**
 * main class for the clients - it´s possible to choose one of the clients with there enabled protocol and connect to the server
 * @param _argc programparameter
 * @param _argv values for port(index: 1), ipv4 adress(index: 2) and ipv6 adress(index: 3)
 * @return
 */
int main(int _argc, char **_argv) {
    //runs server aslong value gets false
    //bool client_run = true;

    //1.2a

    //2.1a
    //choose client
    cout << "\n C++ Client Menu: \n---------------\n 1. Start TCP v4 Echo Client\n 2. Start TCP v6 Echo Client\n 3. Start UDP    Echo Client\n 4. Start TCP    HTTP Client\n 5. Start TCP    Envi Client\n 6. EXIT\n---------------\n Choose client to start: ";
    char type_char[BUFFER_SIZE];
    cin.getline(type_char, BUFFER_SIZE);
    int type = atoi(type_char);

    switch (type) {
        case 1: {
            TCP_v4_client client = TCP_v4_client();
            client.InitializeSocket(_argv);
            break;
        }
        case 2: {
            TCP_v6_client clientv6 = TCP_v6_client();
            clientv6.InitializeSocket(_argv);
            break;
        }
        case 3: {
            UDP_client clientudp = UDP_client();
            clientudp.InitializeSocket(_argv);
            break;
        }
        case 4: {
            cout << "not supported!";
            break;
        }
        case 5: {
            TCP_Envi_client clientEnvi = TCP_Envi_client();
            clientEnvi.InitializeSocket(_argv);
            break;
        }
        default:
            cout << "No valid input!";
            return 0;
    }




    /*
    //1.1a
    //socket
    SOCKET mCommSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mCommSocket == -1) {
        std::cout << "Error";
        return 0;
    }

    //connect
    int port = atoi(_argv[1]);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(_argv[2]);

    int rVal_connect = connect(mCommSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));
    if (rVal_connect == -1) {
        std::cout << "Error!";
        return 0;
    }

    //1.1b --> changed values in "Edit Configurations"
    cout << "--- 1.1b --- \n";
    cout << _argv[1] << "\n";
    cout << _argv[2] << "\n\n";

    //1.1c
    //send
    cout << "--- 1.1c --- \n";

    while (client_run == true) {
        char msg_send[BUFFER_SIZE];
        std::cout << "enter a message: ";
        cin.getline(msg_send, BUFFER_SIZE);
        int msg_sendSize = strlen(msg_send);


        //shutdown server
        char shutdown_string[] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_send);

        if (shutdown_val == 0) {
            int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                return 0;
            }

            //empty char array
            memset(msg_send, 0, sizeof(msg_send));

            cout << "Server & Client shutdown!";
            return 0;
        }

        //quit client
        char quit_string[] = "quit";
        int quit_val = strcmp(quit_string, msg_send);

        if (quit_val == 0) {
            int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                return 0;
            }

            //empty char array
            memset(msg_send, 0, sizeof(msg_send));

            cout << "Client quit!";
            return 0;
        }


        //send message if message is not "quit" or "shutdown"
        int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
        if (rVal_send == -1) {
            std::cout << "Error!";
            return 0;
        }

        //empty char array
        memset(msg_send, 0, sizeof(msg_send));



        //recv
        char msg_recv[BUFFER_SIZE];
        int rVal_recv = recv(mCommSocket, msg_recv, BUFFER_SIZE, 0);
        if (rVal_recv == -1) {
            std::cout << "Error!";
            return 0;
        }
        cout << msg_recv;
        cout << "\n";

    }


    cout << "all went fine!";


/*


    /*



    //close
    int rVal_close = close(mCommSocket);
    if (rVal_close == -1) {
        std::cout << "Error!";
        return 0;
    }
     */

}

#endif
