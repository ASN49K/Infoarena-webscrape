#include <cstdio>
using namespace std;

int c[1025][1025];

int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    int i,j,m,n,k=0,a[1025],b[1025],d[1024];
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;++i) scanf("%d",&a[i]);
    for(i=1;i<=n;++i) scanf("%d",&b[i]);
    for(i=1;i<=m;++i)
    {
        for(j=1;j<=n;++j)
        {
            if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
            else c[i][j]=c[i-1][j]>c[i][j-1] ? c[i-1][j]:c[i][j-1];
        }
    }
    i=m;j=n;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            d[k++]=a[i];
            --i;--j;
        }
        else
        {
            c[i-1][j]>c[i][j-1] ? --i : --j;
        }
    }
    printf("%d\n",k);
    for(i=k-1;i>=0;--i) printf("%d ",d[i]);
    printf("\n");
    return 0;
}
