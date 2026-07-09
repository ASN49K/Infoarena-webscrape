#include <bits/stdc++.h>

using namespace std;

FILE *F=fopen("euclid2.in", "r"), *G=fopen("euclid2.out", "w");

int n, x, y;

int main()
{
    fscanf(F, "%d ", &n);
    while(n--)
    {
        fscanf(F, "%d %d ",&x, &y);
        fprintf(G, "%d\n", __gcd(x, y));
    }
    return 0;
}
