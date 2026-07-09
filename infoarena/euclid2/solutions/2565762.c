#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;

    scanf("%d %d", &a, &b);

    while(b)
    {
        c = a % b;
        a = b;
        b = c;
    }

    printf("%d", a);

    return 0;
}
