#include "commonheader.h"

#define filepath "/Users/minxfeng/Documents/TDS/tds.pcap"

#include "ethernet_frame.h"
#include <openssl/evp.h>




void loopProc(u_char *, const struct pcap_pkthdr *, const u_char *);

void checkBigendianOrLittleendian() {
    union {
        short s;
        char c[sizeof(short)];
    } un;
    un.s = 0x0102;
    if(sizeof(short)==2) {
        if(un.c[0]==1 && un.c[1] == 2)
            printf("big-endian\n");
        else if (un.c[0] == 2 && un.c[1] == 1)
            printf("little-endian\n");
        else
            printf("unknown\n");
    } else {
        printf("sizeof(short)= %d\n", sizeof(short));
    }
}

int main() {

    OpenSSL_add_all_algorithms();

    char errbuf[PCAP_ERRBUF_SIZE];

    pcap_t *handler= pcap_open_offline(filepath,errbuf);
    if(handler==NULL){
        std::cout<<errbuf<<std::endl;
    }


    if(pcap_loop(handler,0,loopProc,NULL)!=0){
        std::cout<<"Error Occurred during loop function!"<<std::endl;
    }

    pcap_close(handler);
    return 0;
}

void loopProc(u_char *, const struct pcap_pkthdr *header, const u_char *content)
{

    boost::shared_array<char> pdata(new char[header->caplen]);
    memcpy(pdata.get(),content,header->caplen);

    boost::shared_ptr<ethernet_frame> frame(new ethernet_frame);
    frame.get()->setData(pdata,header->caplen);



}