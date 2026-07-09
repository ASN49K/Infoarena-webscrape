#include <cstdio>
long i,j,m,n,a[1025],b[1025],v[1025][1025],d[1025];
int main ()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%ld%ld",&n,&m);
    for (i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    for (j=1;j<=m;j++)
        scanf("%ld",&b[j]);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            if (a[i]==b[j])
                v[i][j]=v[i-1][j-1]+1;
            else
                v[i][j]=(v[i-1][j]<v[i][j-1]?v[i][j-1]:v[i-1][j]);
        }
    for (i=n,j=m;i>0;)
    {
        if (a[i]==b[j])
        {
            d[++d[0]]=a[i];
            i--;
            j--;
        }
        else if (v[i][j-1]>v[i-1][j])
            j--;
        else
            i--;
    }
    printf("%ld",d[0]);
    printf("\n");
    for (i=d[0];i>0;i--)
        printf("%ld ",d[i]);
}