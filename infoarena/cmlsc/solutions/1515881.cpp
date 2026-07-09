#include <cstdio>
using namespace std;
int s[6000001],max=-2147483647;
FILE *in,*out;
int main()
{
    in=fopen("ssm.in","r");
    out=fopen("ssm.out","w");
    int  n,i,x,maxi;
    fscanf(in,"%d",&n);
    fscanf(in,"%d",&x);
    s[1]=x;
    for(i=2;i<=n;++i)
    {
        fscanf(in,"%d",&x);
        if(s[i-1]+x<x)s[i]=x;
        else s[i]=s[i-1]+x;
        if(max<s[i])
        {
            max=s[i];
            maxi=i;
        }
    }
    if(max>0)
    {   for(i=maxi;s[i]>=0;--i);
        ++i;
    }
    else i=maxi;
    fprintf(out,"%d %d %d\n",max,i,maxi);
    fclose(in);fclose(out);
    return 0;
}
