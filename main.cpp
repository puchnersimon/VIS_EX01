#include <iostream>
#include "TCP_v4_Echo_server.hpp"

int main(char **_argv) {

    TCP_server server = new TCP_server();

    server.InitializeSocket(_argv);



    return 0;
}
