#include <iostream>
#include <pcap.h>
#include <openssl/ssl.h>

#define filepath "/Users/minxfeng/Documents/TDS/test.pcap"

int main() {
    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *pt= pcap_open_offline(filepath,errbuf);
    if(pt==NULL){
        std::cout<<errbuf<<std::endl;
    }


    std::cout << "Hello, World!" << std::endl;
    return 0;
}