#include <stdio.h>

using namespace std;
FILE *fin=fopen("ssm.in","r");
FILE *fout=fopen("ssm.out","w");
long long s,smax;
int i1,i2,n,i,x,i2max,i1max;
int main()
{
    fscanf(fin,"%d",&n);
    i2=0;
    i1=1;
    for(i=1;i<=n;i++)
    {
        i2++;
        fscanf(fin,"%d",&x);
        s+=x;
        if(s<0)
        {
            s=0;
            if(i<n)i1=i+1;
            else i1=i;
            i2=i;
        }
        if(s>smax)
        {
            smax=s;
            i1max=i1;
            i2max=i2;
        }
    }
     if(s>smax&&s!=0)
        {
            smax=s;
            i1max=i1;
            i2max=i2;
        }
    fprintf(fout,"%lld %d %d",smax,i1max,i2max);
    return 0;
}
