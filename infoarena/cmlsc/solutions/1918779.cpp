#include <cstdio>
using namespace std;
int m,n,i,j,a[1024],b[1024],dp[1024][1024],sir[1024],bst;
int maxim(int x, int y)
{
    if(x>y) return x;
    else return y;
}
int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        scanf("%d",&b[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=maxim(dp[i-1][j],dp[i][j-1]);
        }
        for (i=m,j=n;i>0,j>0;)
        if (a[i] == b[j])
            sir[++bst] = a[i], --i, --j;
        else if (dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;
    printf("%d\n", bst);
    for (i = bst; i; --i)
        printf("%d ", sir[i]);
    return 0;
}
