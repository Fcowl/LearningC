#include <stdio.h>
#include <stdint.h>

int main(void) {
    int packet_id;
    int tmp_status_code;
    float voltage;
    scanf("%x %o %f", &packet_id, &tmp_status_code, &voltage);
    uint8_t status_code = tmp_status_code;

    uint16_t checksum = packet_id+status_code;

    printf("packet_id: %d \n",packet_id);
    printf("status_code: %d \n",status_code);
    printf("status_char: %c \n",status_code);
    printf("voltage: %.2f \n",voltage);
    printf("checksum: %d \n",checksum);
    return 0;
}