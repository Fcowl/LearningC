#include <stdio.h>

#define DAYS_IN_YEAR 365
#define HOURS_IN_DAY 24
#define TICKS_IN_HOUR 3600

int main(void) {
    int years = 90;
    long long days = years * DAYS_IN_YEAR;
    long long hours = days*HOURS_IN_DAY;
    long long ticks = hours*TICKS_IN_HOUR;

    printf("%lld | %lld | %lld | %d",
                ticks, hours, days, years);
    return 0;
}
