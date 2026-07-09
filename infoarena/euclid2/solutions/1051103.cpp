#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    FILE *in, *out;
    in = fopen("euclid2.in","r");
    out = fopen("euclid2.out", "w");
    int a,r,b,n,i;
    fscanf(in, "%d", &n);
    for(i=1; i<=n; i++)
    {
        fscanf(in, "%d", &a);
        fscanf(in, "%d", &b);
        while(b != 0)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(out,"%d", a);
    }
    return 0;
}
