#include <cstdio>
#include <algorithm>
using namespace std;
int n,m,v[1100][1100],a[1100],b[1100],i,maxy,j,V[1100],nr;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for (i=1; i<=n; i++)
        scanf("%d ",&a[i]);
    for (i=1; i<=m; i++)
        scanf("%d",&b[i]);
    for (i=1; i<=m; i++)
        if (v[1][i-1]==0)
        {
            if (b[i]==a[1])v[1][i]=1;
        }
        else v[1][i]=1;
    for (i=1; i<=n; i++)
        if (v[i-1][1]==0)
        {
            if (b[1]==a[i])v[i][1]=1;
        }
        else v[i][1]=1;
    for (i=2; i<=n; i++)
        for (j=2; j<=m; j++)
        {
            if (a[i]==b[j])v[i][j]=1+v[i-1][j-1];
            else v[i][j]=max(v[i][j-1],v[i-1][j]);
        }
    printf("%d\n",v[n][m]);
    i=n;
    j=m;
    nr=v[n][m];
    while (i>0&&j>0&&nr>0)
    {
        if (a[i]==b[j])
        {
            V[nr]=a[i];
            nr--;
            i--;
            j--;
        }
        else
        {
            if (v[i-1][j]>v[i][j-1])

                i--;

            else j--;
        }
    }
    for (i=1; i<=v[n][m]; i++)
        printf("%d ",V[i]);
    printf("\n");
    return 0;
}
