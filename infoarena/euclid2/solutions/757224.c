#include <stdio.h>
#include <stdlib.h>

int gcd(int a, int b)
{
    int r;
    while (b != 0)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

int main()
{
    int n, i, a, b;
    int fr = fopen("euclid2.in", "r");
    int fd = fopen("euclid2.out", "w");
    fscanf(fr, "%d", &n);
    for (i = 0; i < n; i++)
    {
        fscanf(fr, "%d %d", &a, &b);
        fprintf(fd, "%d\n", gcd(a, b));
    }
    fclose(fr);
    fclose(fd);
}
