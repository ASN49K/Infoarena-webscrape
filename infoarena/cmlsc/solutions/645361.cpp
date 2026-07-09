#include <cstdio>
#include <algorithm>
using namespace std;
int m,n,i,j,x;
short int v[1200],MAX,a[1200],b[1200],d[1200][1200];
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (i=1;i<=n;i++) scanf("%hi",&a[i]);
    for (i=1;i<=m;i++) scanf("%hi",&b[i]);
    for (i=1;i<=m;i++) if (a[1]==b[i]) d[1][i]=d[1][i-1]+1; else d[1][i]=d[1][i-1];
    for (i=1;i<=n;i++) if (a[i]==b[1]) d[i][1]=d[i-1][1]+1; else d[i][1]=d[i-1][1];
    for (i=2;i<=n;i++)
    for (j=2;j<=m;j++)
    if (a[i]==b[j]) d[i][j]=d[i-1][j-1]+1; else d[i][j]=max(d[i][j-1],d[i-1][j]);
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
       if (d[i][j]>MAX) MAX=d[i][j];
    }
    j=m;i=n;
    while ((i>0)&&(j>0))
    {
        if (a[i]==b[j]) {x++;v[x]=a[i];i--;j--;}
        else {if (d[i-1][j]>=d[i][j-1]) i--; else j--;}
    }
    printf("%d\n",MAX);
    for (i=x;i>=1;i--) printf("%d ",v[i]);
    return 0;
}
