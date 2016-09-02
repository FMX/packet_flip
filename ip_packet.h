//
// Created by MINX Feng on 16/9/2.
//

#ifndef PACKET_FLIP_IP_PACKET_H
#define PACKET_FLIP_IP_PACKET_H
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <boost/shared_array.hpp>
#include "structs.h"
#include <bitset>
#include <vector>

class ip_packet {
private:
    std::bitset<4> version;
    std::bitset<4> headerlen;
    unsigned char tos;
    unsigned short totallen;
    unsigned short identifier;
    std::bitset<3> flag;
    std::bitset<13> offset;
    ip_addr src;
    ip_addr dst;
    boost::shared_array<char> packet;

public:
    ip_packet();
    void setData(boost::shared_array<char> data);
};


#endif //PACKET_FLIP_IP_PACKET_H
