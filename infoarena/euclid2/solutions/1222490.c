#include <stdio.h>

int T;

int euclid(int a, int b)
{
    int t;

    if (a < b)
    {
        t = a;
        a = b;
        b = t;
    }

    while (b > 0)
    {
        t = a % b;
        a = b;
        b = t;
    }

    return a;
}

int main()
{       
    FILE* f = fopen("euclid2.in", "r");
    FILE* g = fopen("euclid2.out", "w");

    fscanf(f, "%d", &T);

    for (int i = 0; i < T; ++i)
    {
        int a, b;

        fscanf(f, "%d%d", &a, &b);

        int r = euclid(a, b);

        fprintf(g, "%d\n", r);
    }

    return 0;
}
