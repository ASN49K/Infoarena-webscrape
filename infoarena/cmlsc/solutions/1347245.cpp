#include <cstdio>
#include <algorithm>
using namespace std;

int n,m,k,a[1025],b[1025],d[1025][1025],r[1024];

void citire()
{
    freopen("cmlsc.in","r",stdin);
    scanf("%d%d",&n,&m);
    int i;
    for(i=1;i<=n;++i) scanf("%d",&a[i]);
    for(i=1;i<=m;++i) scanf("%d",&b[i]);
}

void lungime()
{
    int i,j;
    for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j)
        {
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
            else d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    }
}

void refacere()
{
    int i=n,j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            r[k++]=a[i];
            --i;--j;
        }
        else
        {
            if(j-1>0) --j;
            else --i;
        }
    }
}

void scrie()
{
    freopen("cmlsc.out","w",stdout);
    printf("%d\n",d[n][m]);
    for(int i=k-1;i>=0;--i) printf("%d ",r[i]);
    printf("\n");
    fclose(stdout);
}

int main()
{
    citire();
    lungime();
   // for(int i=0;i<=n;++i){for(int j=0;j<=m;++j) printf("%d ",d[i][j]);printf("\n");}
    refacere();
    scrie();
    return 0;
}
