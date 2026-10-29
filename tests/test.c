#include <stdio.h>
#define HEIGHT 5

int main(void)
{
    unsigned int option = ((111260445 + (0 + 6)) % 30) + 1; // 22

    for (size_t i = 1; i <= HEIGHT; i++)
    {
        for (size_t j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
