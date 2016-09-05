//
// Created by MINX Feng on 16/9/2.
//

#ifndef PACKET_FLIP_ETHERNET_FRAME_H
#define PACKET_FLIP_ETHERNET_FRAME_H

#include "structs.h"
#include "ip_packet.h"
#include "commonheader.h"

class ethernet_frame {
private:
    mac_addr dst;
    mac_addr src;
    unsigned short type;
    unsigned int crc;

    boost::shared_ptr<ip_packet> ippacket;
    boost::shared_array<char> arraydata;
public:
    ethernet_frame();
    ethernet_frame(unsigned char header[18]);
    bool isContainIPPacket();
    boost::shared_ptr<ip_packet>  getIpPacket();
    void setData(boost::shared_array<char> array,int datalen);
};


#endif //PACKET_FLIP_ETHERNET_FRAME_H
