#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,v1[1030],v2[1030],v[1030],a[1030][1030];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&v1[i]);
    }
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&v2[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if (v1[i]!=v2[j])
            {
                a[i][j]=max(a[i-1][j],a[i][j-1]);
            }
                else
            {
                a[i][j]=a[i-1][j-1]+1;
            }
        }
    }
    printf("%d \n",a[n][m]);
    int elemente=0,x=n,y=m;
    while (elemente<a[n][m])
    {
        if (v1[x]==v2[y])
        {
            v[++elemente]=v1[x];
            x--;
            y--;
        }
            else
        {
            if (a[x-1][y]<a[x][y-1]) y--;
                else x--;
        }
    }
    for(int i=elemente;i>=1;i--) printf("%d ",v[i]);
    printf("\n");
    return 0;
}
