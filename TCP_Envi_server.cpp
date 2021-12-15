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
#include <chrono>
#include <cstdlib>

// ---
#include <pcap/socket.h>
#define BUFFER_SIZE 1024


#include "TCP_Envi_server.hpp"

struct socketParam {
    int mCommSocket;
    int mServerSocket;
    sockaddr_in saddr;
};


//constructor
TCP_Envi_server::TCP_Envi_server() {
    mServerSocket = 0;
    mCommSocket = 0;
}

//destructor
TCP_Envi_server::~TCP_Envi_server() {

}

//initialize-methode
void TCP_Envi_server::InitializeSocket(char **_argv) {
    createSocket();
    bindSocket(_argv);
    listenSocket();
    acceptClient();
}

//create-Socket
void TCP_Envi_server::createSocket() {

    mServerSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    //errorhandling - if serversocket cannot created, program exits with errorcode: -1
    if (mServerSocket == -1) {
        exit(-1);
    }
}

//bind-Socket
void TCP_Envi_server::bindSocket(char **_argv) {

    int port = atoi(_argv[1]);
    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(port);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    int rVal_bind = ::bind(mServerSocket, (sockaddr *) &serverAddr, sizeof(serverAddr));

    //errorhandling - if serversocket cannot created, program exits with errorcode: -1
    if (rVal_bind == -1) {
        exit(-1);
    }
}

//setSocketOptions
//void TCP_v4_Echo_server::setSocketOptions() {}



//listen-Socket
void TCP_Envi_server::listenSocket() {

    int rVal_listen = listen(mServerSocket, 10);
    if (rVal_listen == -1) {
        exit(-1);
    }
}

//accept-Client
void TCP_Envi_server::acceptClient() {
    sockaddr_in clientAddr;
    socklen_t clientAddrSize = sizeof(clientAddr);
    mCommSocket = accept(mServerSocket, (sockaddr *) &clientAddr, &clientAddrSize);
    //errorhandling
    if (mCommSocket == -1) {
        exit(-1);
    }

    //create thread
    socketParam* parameter = new socketParam();
    parameter->mCommSocket = mCommSocket;
    parameter->mServerSocket = mServerSocket;
    parameter->saddr = clientAddr;

    pthread_t threadID;
    int rVal = pthread_create(&threadID, NULL, clientCommunicaton, (void*) parameter);
    //errorhandling
    if (rVal != 0) {
        exit(-1);
    }
    acceptClient();
}

void *TCP_Envi_server::clientCommunicaton(void *_parameter) {
    //for thread
    socketParam* p = (socketParam *) _parameter;
    int commSocket = p->mCommSocket;
    int serverSocket = p->mServerSocket;
    sockaddr_in clientAddr = p->saddr;


    while (1) {
        char msg_recv[BUFFER_SIZE];
        //empty char array
        memset(msg_recv, 0, sizeof(msg_recv));

        int rVal_recv = recv(commSocket, msg_recv, BUFFER_SIZE, 0);
        if (rVal_recv == -1) {
            std::cout << "Error!";
            exit(0);
        }


        //quit client - compare char array
        char quit_string[BUFFER_SIZE] = "quit";
        int quit_val = strcmp(quit_string, msg_recv);

        //shutdown server - compare char array
        char shutdown_string[BUFFER_SIZE] = "shutdown";
        int shutdown_val = strcmp(shutdown_string, msg_recv);

        if (shutdown_val == 0) {
            std::cout << "Server & Client shutdown!\n";
            //close socket
            close(commSocket);
            close(serverSocket);
            exit(0);
            //quit only client
        } else if (quit_val == 0) {
            std::cout << "Client quit!\n";
            memset(msg_recv, 0, sizeof(msg_recv));

            //wait for new client - wait as long a new client will connect to server
            //acceptClient();
            break;
        }

        //send sensortypes
        char sensortypes_string[] = "getSensortypes()#";
        int sensortypes_val = strcmp(sensortypes_string, msg_recv);
        if (sensortypes_val == 0) {
            //send
            char *msg_send = "light;noise;air#";
            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(commSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }
            std::cout << "Sensortypes sendet!\n";
        }

        //send sensor(air)
        char air_string[] = "getSensor(air)#";
        int air_val = strcmp(air_string, msg_recv);
        if (air_val == 0) {
            //get timestamp
            const auto time = std::chrono::system_clock::now();
            long timestamp_long = std::chrono::system_clock::to_time_t(time);
            std::string time_string = std::to_string(timestamp_long);
            char timestamp[BUFFER_SIZE];
            strcpy(timestamp, time_string.c_str());


            char msg_send[BUFFER_SIZE];
            strcat(msg_send, timestamp);
            strcat(msg_send, "|air:");
            for (int i = 0; i < 3; i++) {
                //convert random integer to string
                int random = rand() % 100;
                std::string s = std::to_string(random);
                char string[BUFFER_SIZE];
                strcpy(string, s.c_str());
                strcat(msg_send, string);
                if (i < 2) {
                    strcat(msg_send, ";");
                }
            }
            strcat(msg_send, "#");

            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(commSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }
            std::cout << "AirSensor sendet!\n";
        }

        //send sensor(noise)
        char noise_string[] = "getSensor(noise)#";
        int noise_val = strcmp(noise_string, msg_recv);
        if (noise_val == 0) {
            //get timestamp
            const auto time = std::chrono::system_clock::now();
            long timestamp_long = std::chrono::system_clock::to_time_t(time);
            std::string time_string = std::to_string(timestamp_long);
            char timestamp[BUFFER_SIZE];
            strcpy(timestamp, time_string.c_str());


            char msg_send[BUFFER_SIZE];
            strcat(msg_send, timestamp);
            strcat(msg_send, "|noise:");
            //convert random integer to string
            int random = rand() % 100;
            std::string s = std::to_string(random);
            char string[BUFFER_SIZE];
            strcpy(string, s.c_str());
            strcat(msg_send, string);
            strcat(msg_send, "#");



            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(commSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }
            std::cout << "NoiseSensor sendet!\n";
        }

        //send sensor(light)
        char light_string[] = "getSensor(light)#";
        int light_val = strcmp(light_string, msg_recv);
        if (light_val == 0) {
            //get timestamp
            const auto time = std::chrono::system_clock::now();
            long timestamp_long = std::chrono::system_clock::to_time_t(time);
            std::string time_string = std::to_string(timestamp_long);
            char timestamp[BUFFER_SIZE];
            strcpy(timestamp, time_string.c_str());

            char msg_send[BUFFER_SIZE];
            strcat(msg_send, timestamp);
            strcat(msg_send, "|light:");
            //convert random integer to string
            int random = rand() % 100;
            std::string s = std::to_string(random);
            char string[BUFFER_SIZE];
            strcpy(string, s.c_str());
            strcat(msg_send, string);
            strcat(msg_send, "#");

            //send message with values
            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(commSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }
            std::cout << "LightSensor sendet!\n";
        }



        //send allsensors
        char allsensortypes_string[] = "getAllSensors()#";
        int allsensortypes_val = strcmp(allsensortypes_string, msg_recv);
        if (allsensortypes_val == 0) {
            //get timestamp
            const auto time = std::chrono::system_clock::now();
            long timestamp_long = std::chrono::system_clock::to_time_t(time);
            std::string time_string = std::to_string(timestamp_long);
            char timestamp[BUFFER_SIZE];
            strcpy(timestamp, time_string.c_str());

            //send
            char msg_send[BUFFER_SIZE];
            strcat(msg_send, timestamp);
            strcat(msg_send, "|light;");
            //convert random integer to string
            int random = rand() % 100;
            std::string s = std::to_string(random);
            char string[BUFFER_SIZE];
            strcpy(string, s.c_str());
            strcat(msg_send, string);
            strcat(msg_send, "|");
            strcat(msg_send, "noise;");
            random = rand() % 100;
            s = std::to_string(random);
            strcpy(string, s.c_str());
            strcat(msg_send, string);
            strcat(msg_send, "|");
            strcat(msg_send, "air;");
            for (int i = 0; i < 3; i++) {
                //convert random integer to string
                random = rand() % 100;
                s = std::to_string(random);
                strcpy(string, s.c_str());
                strcat(msg_send, string);
                if (i < 2) {
                    strcat(msg_send, ";");
                }
            }
            strcat(msg_send, "#");


            int msg_sendSize = strlen(msg_send);
            int rVal_send = send(commSocket, msg_send, msg_sendSize, 0);
            if (rVal_send == -1) {
                std::cout << "Error!";
                exit(0);
            }
            std::cout << "AllSensors sendet!\n";
        }
    }
}
