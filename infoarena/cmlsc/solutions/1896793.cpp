#include <cstdio>
#define nmax 1025
using namespace std;

int x[nmax],y[nmax],a[nmax][nmax],n,m,v[nmax],nr;

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",&x[i]);
    for(int i=1;i<=m;i++)
        scanf("%d",&y[i]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
                a[i][j]=1+a[i-1][j-1];
            else
                a[i][j]=a[i-1][j]>a[i][j-1]?a[i-1][j]:a[i][j-1];
    printf("%d\n",a[n][m]);
    while(n>0&&m>0)
    {
        if(x[n]==y[m])
        {
            v[nr++]=x[n];
            n--;m--;
        }
        else
            if(a[n-1][m]>a[n][m-1])
                n--;
            else
                m--;
    }
    for(int i=nr-1;i>=0;i--)
        printf("%d ",v[i]);
    return 0;
}
