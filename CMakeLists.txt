cmake_minimum_required(VERSION 3.10)
project(AetherNetworking)

set(CMAKE_C_STANDARD 99)

add_executable(node2
        src/main.c
        src/aodv.c
        src/network.c
        src/routing_table.c
)

