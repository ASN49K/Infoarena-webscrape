#include <bits/stdc++.h>

using namespace std;

FILE *fin = fopen("euclid2.in", "r");
FILE *fout = fopen("euclid2.out", "w");

inline int Euclid(int a, int b)
{
    int r;
    while(b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main()
{
    int i, a, b, N;
    fscanf(fin, "%d", &N);
    for(i = 1; i <= N; i++)
    {
        fscanf(fin, "%d %d", &a, &b);
        fprintf(fout, "%d\n", Euclid(a, b));
    }
    return 0;
}
