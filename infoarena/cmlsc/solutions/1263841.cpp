#include<cstdio>
#include<algorithm>
using namespace std;
int a[1030],b[1030],n,m,subsir[1030][1030],v[1030];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
    {
        if (a[i]==b[j]) subsir[i][j]=subsir[i-1][j-1]+1;
            else
        subsir[i][j]=max(subsir[i-1][j],subsir[i][j-1]);
    }
    printf("%d\n",subsir[n][m]);
    int elemente=0,x=n,y=m;
    while (elemente<subsir[n][m])
    {
        if (a[x]==b[y])
        {
           // printf("%d ",a[x]);

            elemente++;
            v[elemente]=a[x];
            x--;y--;
        }
            else
        if (subsir[x-1][y]>subsir[x][y-1]) x--;
            else y--;
    }
    for (int i=elemente;i>=1;i--) printf("%d ",v[i]);
    printf("\n");
    return 0;
}
