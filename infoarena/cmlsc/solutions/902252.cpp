#include<cstdio>
#include<algorithm>
#define DMAX 1030
using namespace std;
FILE *fin= fopen("cmlsc.in", "r");
FILE *fout=fopen("cmlsc.out","w");
int i,j,n,m,a[DMAX],b[DMAX],t[DMAX][DMAX];
int main()
{
    fscanf(fin,"%d%d",&n,&m);
    for(i=1;i<=n;++i)
        fscanf(fin,"%d",&a[i]);
    for(i=1;i<=m;++i)
        fscanf(fin,"%d",&b[i]);
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(a[i]==b[j])
                t[i][j]=1+t[i-1][j-1];
            else
                t[i][j]=max(t[i-1][j],t[i][j-1]);
    fprintf(fout,"%d\n",t[n][m]);

    int s=t[n][m],k=0,v[DMAX];
    i=n; j=m;
    while(s)
    {
        if(a[i]==b[j])
        {
            v[++k]=a[i];
            --s; --i; --j;
        }
        else
            if(t[i-1][j]==t[i][j])
                --i;
            else
                --j;

    }
    for(i=k;i>=1;--i)
        fprintf(fout,"%d ",v[i]);
    return 0;
}
