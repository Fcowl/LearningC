#include <stdio.h>
#include <float.h>

int main(void) {
    int fl_size = sizeof(float);
    int db_size = sizeof(double);
    int ldb_size = sizeof(long double);

    printf("float: size=%d digits=%d, max=%e    \n",fl_size,FLT_DIG,FLT_MAX);
    printf("double: size=%d digits=%d, max=%e   \n",db_size,DBL_DIG,DBL_MAX);
    printf("lDouble: size=%d digits=%d, max=%Le \n",ldb_size,LDBL_DIG,LDBL_MAX);
    // в зависимости от системы размер L_double может быть разным, от 12 байт до 16 байт
    return 0;
}