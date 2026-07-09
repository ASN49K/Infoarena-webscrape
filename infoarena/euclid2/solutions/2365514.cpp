#include "stdio.h"

int gcd(int a, int b)
{
    while(a != b) {
        a > b ? a -= b : b -= a;
    }

    return a;
}

int main()
{
    int T;
    int a, b;
    int d;

    FILE *inFile = fopen("euclid2.in", "r");
    FILE *outFile = fopen("euclid2.out", "w");

    fscanf(inFile, "%d", &T);

    for(int i; i < T; i++) {
        fscanf(inFile, "%d", &a);
        fscanf(inFile, "%d", &b);

        d = gcd(a, b);

        fprintf(outFile, "%d\n", d);
    }

    fclose(inFile);
    fclose(outFile);
    return 0;
}