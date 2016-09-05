//
// Created by MINX Feng on 16/9/2.
//

#ifndef PACKET_FLIP_IP_PACKET_H
#define PACKET_FLIP_IP_PACKET_H

#include "commonheader.h"
#include "structs.h"

class ip_packet {
private:
    unsigned short version;
    unsigned short headerlen;
    unsigned char tos;
    unsigned short totallen;
    unsigned char identifier;
    unsigned short flag;
    unsigned short offset;
    unsigned char ttl;
    unsigned char proto;
    unsigned short checksum;
    ip_addr src;
    ip_addr dst;
    boost::shared_array<char> packet;

public:
    ip_packet();
    void setData(boost::shared_array<char> data);
};


#endif //PACKET_FLIP_IP_PACKET_H
