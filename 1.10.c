#include <stdio.h>

void ping(void) {
    printf("PING");
}

void pong(void) {
    printf("PONG");
}

void handshake(void) {
    ping();
    printf("-");
    pong();
}

int main(void) {
    #define NODE_ID 10
    int packet_size = NODE_ID * 4;
    int total_transfer = packet_size*3;

    handshake();
    printf(":%d\n",packet_size);
    handshake();
    printf(":%d\n",total_transfer);
    printf("SESSION:CLOSED");
    return 0;
}