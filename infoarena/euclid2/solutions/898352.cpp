#include<stdio.h>
#include<algorithm>
using namespace std;
FILE *in,*out;
long int cmmdc(long int a,long int);
long int x,y,n,divizor;
int i;
int main()
{
    in=fopen("euclid2.in","rt");
    out=fopen("euclid2.out","wt");
    fscanf(in,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(in,"%ld%ld",&x,&y);
        divizor=cmmdc(x,y);
        fprintf(out,"%ld\n",divizor);
    }
    fclose(in);
    fclose(out);
    return 0;
}

long int cmmdc(long int a,long int b)
{
    long int r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}
