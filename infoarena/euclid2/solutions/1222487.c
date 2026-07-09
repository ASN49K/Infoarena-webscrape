#include <stdio.h>

int T;

int euclid(int a, int b)
{
    if (!b)
        return a;

    return euclid(b, a%b);
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
