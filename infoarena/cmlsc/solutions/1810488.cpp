#include <cstdio>
#define max(a,b) a>b?a:b
using namespace std;
int na, nb,i,j;
unsigned char a[1030],b[1030];
int comb[1030][1030];
int main()
{
    FILE *in=fopen("cmlsc.in","r"),*out=fopen("cmlsc.out","w");
    fscanf(in,"%d%d",&na,&nb);

    for(i=1;i<=na;++i)fscanf(in,"%d",&a[i]);
    for(i=1;i<=nb;++i)fscanf(in,"%d",&b[i]);


    for(i=1;i<=na;++i)
        for(j=1;j<=nb;++j)
    {
        if(a[i]==b[j])
            comb[i][j]=comb[i-1][j-1]+1;
        else
            comb[i][j]=max(comb[i-1][j],comb[i][j-1]);
    }
    fprintf(out,"%d\n",comb[na][nb]);
    int k=0;
    for(i=na,j=nb;comb[i][j];)
    {
        if(comb[i-1][j]==comb[i][j])--i;
        else if(comb[i][j-1]==comb[i][j])--j;
        else b[++k]=a[i],--i,--j;
    }
    while(k)fprintf(out,"%d ",b[k--]);
    return 0;
}
