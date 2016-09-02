cmake_minimum_required(VERSION 3.6)
project(packet_flip)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/usr/include)
include_directories(/usr/local/include)
link_directories(/usr/lib)
link_directories(/usr/local/lib)
link_libraries(pcap)
link_libraries(ssl)
set(SOURCE_FILES main.cpp ethernet_frame.cpp ethernet_frame.h ip_packet.cpp ip_packet.h structs.h)
add_executable(packet_flip ${SOURCE_FILES})