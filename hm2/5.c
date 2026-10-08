#include <stdio.h>
#include <stdint.h>
#include <math.h>

int main(void) {
    int vl_int8 = (int)pow(2,sizeof(int8_t)*8);
    printf("INT8: size=%d, min=%d, max=%d, values=%d \n",
        (int)sizeof(int8_t), INT8_MIN, INT8_MAX,vl_int8);

    int vl_uint8 = UINT8_MAX+1;
    printf("UINT8: size=%d, min=%d, max=%d, values=%d \n",
        (int)sizeof(uint8_t), 0, UINT8_MAX,vl_uint8);

    int vl_int16 = (int)pow(2,sizeof(int16_t)*8);
    printf("INT16: size=%d, min=%d, max=%d, values=%d \n",
        (int)sizeof(int16_t), INT16_MIN, INT16_MAX,vl_int16);

    unsigned int vl_uint16 = UINT16_MAX+1;
    printf("UINT16: size=%d, min=%d, max=%d, values=%u \n",
        (int)sizeof(uint16_t), 0, UINT16_MAX,vl_uint16);

    long long vl_int32 = (long long)pow(2,sizeof(int32_t)*8);
    printf("INT32: size=%d, min=%d, max=%d, values=%lld \n",
        (int)sizeof(int32_t), INT32_MIN, INT32_MAX,vl_int32);

    unsigned long long vl_uint32 = (unsigned long long)UINT32_MAX+1;
    printf("UINT32: size=%d, min=%d, max=%u, values=%llu \n",
        (int)sizeof(uint32_t), 0, UINT32_MAX,vl_uint32);
    return 0;

}
