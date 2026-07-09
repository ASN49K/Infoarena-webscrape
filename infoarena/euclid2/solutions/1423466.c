#include <stdio.h>
#include <stdint.h>

int main(void)
{
    char *c = "comentarii";
    int i = 0;

    while (*c)
        i += *(c++);

    printf("%x\n", i);

    return 0;
}
