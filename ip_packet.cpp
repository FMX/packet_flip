//
// Created by MINX Feng on 16/9/2.
//

#include "ip_packet.h"

ip_packet::ip_packet(){

}

void ip_packet::setData(boost::shared_array<char> data){
    this->packet=data;
    char tmp=data.get()[0];
    this->version=tmp>>4;
    this->headerlen=tmp&0x0f;
    std::cout<<headerlen*4<<std::endl;
    this->tos=data.get()[1];
//    this->totallen=data.get()[2];
    memcpy(&this->totallen,data.get()+2,2);
    this->totallen= htons(this->totallen);
    this->identifier=data.get()[4];
    this->identifier=data.get()[6]>>5;
    this->offset=data.get()[6];
    this->offset=this->offset<<3;
    this->offset=this->offset>>3;
    this->ttl=data.get()[8];
    this->proto=data.get()[9];
    this->checksum=data.get()[10];

    memcpy(&this->src,data.get()+12,4);
    memcpy(&this->dst,data.get()+16,4);

    std::cout<<"Total length is :"<<this->totallen<<std::endl;

}
