//
// Created by MINX Feng on 16/9/2.
//

#include "ethernet_frame.h"

ethernet_frame::ethernet_frame() {

}

ethernet_frame::ethernet_frame(unsigned char *header) {

}

bool ethernet_frame::isContainIPPacket(){
    if(this->type==0x8000)
        return true;
    else
        return false;
}

boost::shared_ptr<ip_packet>  ethernet_frame::getIpPacket(){

}

void ethernet_frame::setData(boost::shared_array<char> array){
    this->arraydata=array;
    memcpy(&this->dst,this->arraydata.get(),6);
    memcpy(&this->src,this->arraydata.get()+6,6);
    memcpy(&this->type,this->arraydata.get()+12,2);
    if(isContainIPPacket()){
        int len=sizeof(this->arraydata.get());
        len-=14;
        boost::shared_array arr(new char[len]);
        memcpy(arr.get(),this->arraydata.get()+14,len);
        boost::shared_ptr ipptr(new ip_packet());

    }


}