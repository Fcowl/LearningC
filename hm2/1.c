#include <stdio.h>

int main(void) {
    int unit_id;
    int unit_version;
    int unit_status;

    scanf("%d %x %o", &unit_id, &unit_version, &unit_status);

    printf("unit_id: %d \n"
                "UNIT_VERSION: %d \n"
                "UNIT_STATUS: %d \n"
                "SUM: %d \n",
                unit_id, unit_version, unit_status,
                unit_id + unit_version + unit_status);
    return 0;
}