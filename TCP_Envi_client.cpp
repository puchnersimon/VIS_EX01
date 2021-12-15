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

#define BUFFER_SIZE 1024

#include "TCP_Envi_client.hpp"

TCP_Envi_client::TCP_Envi_client() {
    mCommSocket = 0;
}

TCP_Envi_client::~TCP_Envi_client() {

}

void TCP_Envi_client::InitializeSocket(char **_argv) {
    createSocket();
    connectServer(_argv);
    sendMessage();

}

void TCP_Envi_client::createSocket() {
    mCommSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }
}

void TCP_Envi_client::connectServer(char **_argv) {
    int port = atoi(_argv[1]);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = inet_addr(_argv[2]);

    int rVal_connect = connect(mCommSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));
    //errorhandling
    if (rVal_connect == -1) {
        exit(-1);
    }
}

void TCP_Envi_client::sendMessage() {
    std::cout << "Commands:\n - getSensortypes()#\n - getSensor(air)#\n - getSensor(noise)#\n - getSensor(light)#\n - getAllSensors()#\n";

    while (1) {

        char msg_send[BUFFER_SIZE];
        std::cout << "enter a message: ";
        std::cin.getline(msg_send, BUFFER_SIZE);
        int msg_sendSize = strlen(msg_send);


        //shutdown server
        char shutdown_string[] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_send);

        if (shutdown_val == 0) {
            int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                exit(-1);
            }

            //empty char array
            memset(msg_send, 0, sizeof(msg_send));

            std::cout << "Server & Client shutdown!";
            //close socket
            close(mCommSocket);
            exit(0);
        }

        //quit client
        char quit_string[] = "quit";
        int quit_val = strcmp(quit_string, msg_send);

        if (quit_val == 0) {
            int rVal_send = send(mCommSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }

            //empty char array
            memset(msg_send, 0, sizeof(msg_send));

            std::cout << "Client quit!";
            //close socket
            close(mCommSocket);
            exit(0);
        }


        //get Sensortypes
        char sensortypes_string[] = "getSensortypes()#";
        int sensortypes_val = strcmp(sensortypes_string, msg_send);

        //getAllSensors
        char allsensortypes_string[] = "getAllSensors()#";
        int allsensorttypes_val = strcmp(allsensortypes_string, msg_send);

        //getSensor
        char getSensor_string[] = "getSensor(";

        //get sensortypes
        if (sensortypes_val == 0) {
            getSensortypes(msg_send);
        } else if (allsensorttypes_val == 0) {
            //get allsensors
            getAllSensors(msg_send);
        } else if (strstr(msg_send, getSensor_string) != NULL) {
            //getSensor
            getSensor(msg_send);
        } else {
            std::cout << "no valid input!\nCommands:\n - getSensortypes()#\n - getSensor(air)#\n - getSensor(noise)#\n - getSensor(light)#\n - getAllSensors()#\n";
        }

        //empty char array
        memset(msg_send, 0, sizeof(msg_send));
    }
}

void TCP_Envi_client::recvMessage() {
    char msg_recv[BUFFER_SIZE];
    memset(msg_recv, 0, sizeof(msg_recv));
    int rVal_recv = recv(mCommSocket, msg_recv, BUFFER_SIZE, 0);
    if (rVal_recv == -1) {
        std::cout << "Error!";
        exit(0);
    }
    std::cout << msg_recv;
    std::cout << "\n";
}


// 3.1a

void TCP_Envi_client::getSensortypes(char _msg_send[]) {
    //send message if message is "getSensortypes()"
    int msg_sendSize = strlen(_msg_send);
    int rVal_send = send(mCommSocket, _msg_send, msg_sendSize, 0);
    if (rVal_send == -1) {
        std::cout << "Error!";
        exit(0);
    }
    //recv
    recvMessage();
}

void TCP_Envi_client::getSensor(char _msg_send[]) {
    char air_string[] = "getSensor(air)#";
    char noise_string[] = "getSensor(noise)#";
    char light_string[] = "getSensor(light)#";
    int air_val = strcmp(air_string, _msg_send);
    int noise_val = strcmp(noise_string, _msg_send);
    int light_val = strcmp(light_string, _msg_send);

    //if string is equal to comparison, message will be sent
    if (air_val == 0 || noise_val == 0 || light_val == 0) {
        int msg_sendSize = strlen(_msg_send);
        int rVal_send = send(mCommSocket, _msg_send, msg_sendSize, 0);
        if (rVal_send == -1) {
            std::cout << "Error!";
            exit(0);
        }
        //recv
        recvMessage();
    }

}

void TCP_Envi_client::getAllSensors(char _msg_send[]) {
    //send message if message is "getAllSensors()"
    int msg_sendSize = strlen(_msg_send);
    int rVal_send = send(mCommSocket, _msg_send, msg_sendSize, 0);
    if (rVal_send == -1) {
        std::cout << "Error!";
        exit(0);
    }
    //recv
    recvMessage();
}
