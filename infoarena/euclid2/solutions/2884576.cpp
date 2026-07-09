#include <iostream>
#include <cstdio>
using namespace std;
FILE *fin=fopen("euclid2.in", "r");
FILE *fout=fopen("euclid2.out", "w");
int gcd (int a, int b)
{
    int r;
    while (b) {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int t, a, b;
    fscanf(fin, "%d", &t);
    for (int i=1; i<=t; i++) {
        fscanf(fin, "%d%d", &a, &b);
        fprintf(fout, "%d%c", gcd(a, b), '\n');
    }
    return 0;
}
