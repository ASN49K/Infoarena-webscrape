#include <cstdio>
#define Max(a,b) a<b ? b : a
using namespace std;

int C[1024][1024], n, m, i, j, a[1024], b[1024], v[1024], sol;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=m;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i]==b[j])
                C[i][j]=C[i-1][j-1]+1;
                else C[i][j]=Max(C[i-1][j],C[i][j-1]);
    printf("%d\n",C[n][m]);
    i=n; j=m;
    while(i)
    {
        if(a[i]==b[j])
        {
            v[++sol]=a[i];
            i--;
            j--;
        }
        else if(C[i-1][j]<C[i][j-1]) j--;
            else i--;
    }
    for(i=sol;i>=1;i--)
        printf("%d ",v[i]);
    return 0;
}
