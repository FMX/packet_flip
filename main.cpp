#include <iostream>
#include <pcap.h>
#include <openssl/ssl.h>
#include <string>
#include <cstdint>
#include <boost/shared_ptr.hpp>
#include <boost/array.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/shared_array.hpp>

#define filepath "/Users/minxfeng/Documents/TDS/tds.pcap"

#include "ethernet_frame.h"


void loopProc(u_char *, const struct pcap_pkthdr *, const u_char *);



int main() {
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handler= pcap_open_offline(filepath,errbuf);
    if(handler==NULL){
        std::cout<<errbuf<<std::endl;
    }


    if(pcap_loop(handler,0,loopProc,NULL)!=0){
        std::cout<<"Error Occurred during loop function!"<<std::endl;
    }

    pcap_close(handler);

    std::cout<<"Size of long is :"<<sizeof(long)<<std::endl;
    return 0;
}

void loopProc(u_char *, const struct pcap_pkthdr *header, const u_char *content)
{
//    char *newdata=new char[header->caplen];
    boost::shared_array<char> pdata(new char[header->caplen]);
    memcpy(pdata.get(),content,header->caplen);

    boost::shared_ptr<ethernet_frame> frame(new ethernet_frame);
    frame.get()->setData(pdata);

    

}