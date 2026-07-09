#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#define NMax 1100
#define Max(a,b) (a<b) ? b : a
using namespace std;
int a[NMax], b[NMax], d[NMax][NMax], i, j, n, m, v[NMax], sol;
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1; i<=m; i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
            if(a[i]==b[j]) d[i][j]=d[i-1][j-1]+1;
                else d[i][j]=Max(d[i-1][j],d[i][j-1]);
    printf("%d\n",d[n][m]);
    i=n; j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            v[++sol]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]<d[i][j-1]) j--;
            else i--;
    }
    for(i=sol;i>=1;i--)
        printf("%d ",v[i]);
    return 0;
}
