#include <stdio.h>
using namespace std;

int m,n,i,j,a[1025],b[1025],d[1025][1025],v[1025];

int main()
{

    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    scanf("%d %d",&m,&n);

    for (i=1;i<=m;i++) scanf("%d",&a[i]);
    for (i=1;i<=n;i++) scanf("%d",&b[i]);

    for (i=1;i<=m;i++)
    for (j=1;j<=n;j++)
    {
        if (a[i]==b[j])
        {
        d[i][j]=d[i-1][j-1]+1;
            if (v[d[i][j]]==0 ) v[d[i][j]]=a[i];
        }
        else
            if (d[i-1][j]>d[i][j-1])
            d[i][j]=d[i-1][j];
            else
            d[i][j]=d[i][j-1];

    }

    printf("%d\n",d[m][n]);


    for (i=1;i<=d[m][n];i++)
    printf("%d ",v[i]);

    return 0;
}
