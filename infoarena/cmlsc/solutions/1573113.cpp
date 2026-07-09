#include <cstdio>

using namespace std;

FILE *f=fopen("ssm.in","r");
FILE *g=fopen("ssm.out","w");
int n,s,i,x,sc,Max,endd,st;
int main()
{
    fscanf(f,"%d",&n);
    Max=-99999;
    s=1;
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        sc+=x;
        if(sc>Max)
        {
            Max=sc;
            st=s;
            endd=i;
        }
        if(sc<0)
        {
            sc=0;
            s=i+1;
        }
    }
    fprintf(g,"%d %d %d\n",Max,st,endd);
    return 0;
}
