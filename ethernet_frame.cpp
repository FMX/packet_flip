//
// Created by MINX Feng on 16/9/2.
//

#include "ethernet_frame.h"
#include <iostream>

ethernet_frame::ethernet_frame() {

}

ethernet_frame::ethernet_frame(unsigned char *header) {

}

bool ethernet_frame::isContainIPPacket(){
    ntohs(this->type);
    if(this->type==0x008)
        return true;
    else
        return false;
}

boost::shared_ptr<ip_packet>  ethernet_frame::getIpPacket(){

}

void ethernet_frame::setData(boost::shared_array<char> array,int datalen){
    this->arraydata=array;
    memcpy(&this->dst,this->arraydata.get(),6);
    memcpy(&this->src,this->arraydata.get()+6,6);
    memcpy(&this->type,this->arraydata.get()+12,2);
    if(isContainIPPacket()){
        int len=sizeof(this->arraydata.get());
        len=datalen-14;
        boost::shared_array<char> arr(new char[len]);
        memcpy(arr.get(),this->arraydata.get()+14,len);
        boost::shared_ptr<ip_packet> ipptr(new ip_packet());
        ipptr.get()->setData(arr);
//        std::cout<<"find one ip packet"<<std::endl;
    }


}