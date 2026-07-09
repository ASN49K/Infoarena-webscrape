#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{   FILE *in=fopen("nim.in","rt");
    FILE *out=fopen("nim.out","wt");
    int t,i,x,y,n,j;
    fscanf(in,"%d",&t);
    for (i=1;i<=t;i++)
    {
        fscanf(in,"%d",&n);
        fscanf(in,"%d",&x);
        for (j=1;j<n;j++){fscanf(in,"%d",&y);
                          x=x^y;}
        if(x!=0)fprintf(out,"DA\n");
        else fprintf(out,"NU\n");
    }
    return 0;
}
