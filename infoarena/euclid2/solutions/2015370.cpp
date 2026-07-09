#include <bits/stdc++.h>

using namespace std;

FILE *F=fopen("euclid2.in", "r"), *G=fopen("euclid2.out", "w");

int n, x, y, a, b, r;

int main()
{
    fscanf(F, "%d ", &n);
    while(n--)
    {
        fscanf(F, "%d %d ",&x, &y);
        a = x; b = y; r = a%b;
        while(r > 1)
            a = b, b = r, r = a % b;
        if(r == 1) fprintf(G, "%d\n", r);
        else fprintf(G, "%d\n", b);
    }
    return 0;
}
