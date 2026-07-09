#include <stdlib.h>
#include <stdio.h>

int euclid(int a, int b)
{
    int tmp;

    while(b)
    {
        tmp = a%b;
        a = b;
        b = tmp;
    }

    return a;
}

int main()
{
    int A,B,N;

    FILE* in   = fopen("euclid2.in", "r");
    FILE* out = fopen("euclid2.out", "w");

    fscanf(in, "%d", &N);
    while(N)
    {
        fscanf(in, "%d %d", &A, &B);
        fprintf(out, "%d\n", euclid(A,B));
        --N;
    }

    return 0;
}
