#include <cstdio>
#include <algorithm>
using namespace std;
int rez[1025],a[1025],b[1025];
int d[1025][1025];
int main()
{
    int n,m,i,j,z;
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(i=1; i<=n; i++)
        scanf("%d",&a[i]);
    for(i=1; i<=m; i++)
        scanf("%d",&b[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            d[i][j]=max(d[i][j],max(d[i-1][j],d[i][j-1]));
        }
    printf("%d\n",d[n][m]);
    z=d[n][m];
    i=n;
    j=m;
    while(i && j && z)
    {
        if(a[i]==b[j])
        {
            rez[z--]=a[i];
            i--;
            j--;
        }
        else
            if(d[i][j]==d[i-1][j])
                i--;
            else
                j--;
    }
    for(i=1; i<=d[n][m]; i++)
        printf("%d ",rez[i]);

    return 0;
}
