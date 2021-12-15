cmake_minimum_required(VERSION 3.20)
project(VIS_EX01)

set(CMAKE_CXX_STANDARD 14)

add_executable(Server server_main.cpp TCP_v4_Echo_server.hpp TCP_v4_Echo_server.cpp TCP_v6_Echo_server.cpp TCP_v6_Echo_server.hpp UDP_server.cpp UDP_server.hpp TCP_Envi_server.cpp TCP_Envi_server.hpp)
add_executable(Client client_main.cpp TCP_v4_client.cpp TCP_v4_client.hpp TCP_v6_client.cpp TCP_v6_client.hpp UDP_client.cpp UDP_client.hpp TCP_Envi_client.cpp TCP_Envi_client.hpp)
