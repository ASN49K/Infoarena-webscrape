#include <cstdio>
#include <algorithm>
using namespace std;
#define Max 1025

int n,m,a[Max],b[Max],c[Max][Max];

void cmlsc()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if( a[i] == b[j] )c[i][j] = 1 + c[i-1][j-1]; else
    c[i][j] = max( c[i-1][j], c[i][j-1] );
}

void tipar(int n,int m)
{
    if( c[n][m] > 0 )
    {
        if( a[n] == b[m] )
        {
            tipar(n-1,m-1);
            printf("%d ",a[n]);
            return ;
        }
        if( c[n-1][m] > c[n][m-1] )
        {
            tipar(n-1,m);
        } else
        {
            tipar(n,m-1);
        }
    }
}

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

        scanf("%d %d",&n,&m);

        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);

        cmlsc();
        printf("%d\n",c[n][m]);
        tipar(n,m);

    return 0;
}
