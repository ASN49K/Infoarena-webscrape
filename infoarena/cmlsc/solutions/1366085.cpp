#include <cstdio>

using namespace std;
int n,m,i,j,a[1100],b[1100],sir[1100],k[1100][1100];
int mx(int a,int b)
{
    return (a>b ? a:b);
}
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
        k[i][j]=k[i-1][j-1]+1;
    else k[i][j]=mx(k[i-1][j],k[i][j-1]);
    for (i = n, j = m; i; )
        if (a[i] == b[j])
            sir[0]++,sir[sir[0]] = a[i], i--, j--;
        else if (k[i-1][j] < k[i][j-1])
            j--;
        else
            i--;
    printf("%d\n",sir[0]);
    for(i=sir[0];i>0;i--)
    printf("%d ",sir[i]);

    return 0;
}
