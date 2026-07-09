#include <cstdio>
#define max(a,b) ( ((a) > (b)) ? (a) : (b))
using namespace std;
int a[1024],b[1024],d[1024][1024],v[1024];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,m,n;
    scanf("%d %d",&n,&m);
    for(i=1; i<=n; i++)
    scanf("%d",&a[i]);
    for(i=1; i<=m; i++)
    scanf("%d",&b[i]);

    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
    {
        if(a[i] == b[j])
            d[i][j] = 1 + d[i-1][j-1];
        else d[i][j] = max(d[i-1][j],d[i][j-1]);
    }
    i = n;
    j = m;
    int nr = 0;
    while( i && j)
    {
        if(a[i] == b[j])
        {
            v[++nr] = a[i];
            i--;
            j--;
        }
        else
        {
            if(d[i][j-1] > d[i-1][j])
                j--;
            else
                i--;
        }
    }
    printf("%d\n",nr);
    for(i=nr; i>=1; i--)
        printf("%d ",v[i]);
    return 0;
}
