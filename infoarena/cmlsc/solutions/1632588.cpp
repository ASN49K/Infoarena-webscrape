#include <cstdio>
#include <algorithm>
#define MAX 1030
using namespace std;
short n,m,i,j,lmax;
short a[MAX],b[MAX],c[MAX][MAX],d[MAX];
int constrmat(short a[MAX],short b[MAX],short c[MAX][MAX])
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
        }
    return c[n][m];
}
int parcour( short c[MAX][MAX])
{
    int i=n,j=m,nrlen=0;
    while(nrlen<=c[n][m] && i>=1 && j>=1)
    {
        if(a[i]==b[j])
            d[lmax--]=a[i],i-=1,j-=1,nrlen++;
        else if(c[i-1][j]==c[i][j-1])
            i-=1;
        else
        {
            if(c[i-1][j]>c[i][j-1])
                i-=1;
            else j-=1;
        }
    }
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    lmax=constrmat(a,b,c);
    printf("%d \n",lmax);
    parcour(c);
    for(i=1;i<=c[n][m];i++)
        printf("%d ",d[i]);
    return 0;
}
