#include <cstdio>
#include <algorithm>
using namespace std;
int a[2000],b[2000],d[2000][2000],rasp[2000];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    for(i=0;i<=n;i++)
        {
            d[i][0]=0;
            d[i][m+1]=0;
        }
    for(i=0;i<=m;i++)
    {
        d[0][i]=0;
        d[n+1][i]=0;
    }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;++j)
        {
            if(a[i]==b[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    printf("%d\n",d[n][m]);
    i=n;
    j=m;
    while(i>0&&j>0)
    {
        if(a[i]==b[j])
        {
            rasp[d[i][j]]=a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i][j-1]==d[i][j])
                j--;
            else
                i--;
        }
    }
    for(i=1;i<=d[n][m];i++)
        printf("%d ",rasp[i]);
    return 0;
}
