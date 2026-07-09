#include <cstdio>

using namespace std;
int n,m,i,j,a[1100][1100];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d %d",&n,&m);
   /* for(i=1;i<=n;i++)
        scanf("%d",&a[0][i]);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i][0]);
    for(i=1;i<=n;i++)
        if(a[0][i]==a[0][1])
     //   a[]
    for(i=2;i<=n;i++)
    {
        a[1][i]+=a[1][i-1];
        if(a[0][i]==a[1][0])a[1][i]++;
    }
    for(i=2;i<=m;i++)
    {
        a[i][1]+=a[i-1][1];
        if(a[i][0]==a[0][1])a[i][1]++;
    }
    for(i=2;i<=n;i++)
        for(j=2;j<=m;j++)
        a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }*/
    return 0;
}
