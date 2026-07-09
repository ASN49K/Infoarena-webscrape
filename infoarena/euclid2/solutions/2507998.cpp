#include <bits/stdc++.h>

using namespace std;

int main()
{
    FILE * in=fopen("euclid2.in","r");
    FILE * out=fopen("euclid2.out","w");
    int n,c=0,a,b,r;
    fscanf(in,"%d",&n);
    while (c<n)
    {
        fscanf(in,"%d%d",&a,&b);
        c++;
        while (b)
        {
            r = a % b;
            a = b;
            b = r;
        }
        fprintf(out,"%d\n",a);
    }
    return 0;
}
