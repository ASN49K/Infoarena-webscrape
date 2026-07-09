#include <cstdio>
#include <algorithm>
using namespace std;
int a[1025], b[1025], c[1025][1025], sol[1025], n, m, i, j, Max;
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
               if(a[i]==b[j]) c[i][j]=c[i-1][j-1]+1;
               else c[i][j]= max(c[i-1][j],c[i][j-1]);
    i=n;
    j=m;
    Max=c[i][j];
    int x=0;
    while(x<Max)
    {
        if(a[i]==b[j]) {sol[++x]=a[i]; i--; j--;}
        else c[i-1][j]>c[i][j-1] ? i-- : j--;
    }
    printf("%d\n",Max);
    for(i=Max; i>=1;i--)
        printf("%d ",sol[i]);

    return 0;
}
