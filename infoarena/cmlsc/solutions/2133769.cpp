#include <cstdio>
#include <algorithm>

using namespace std;

int dp[1025][1025], sol[1025], k=1;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    int n,m, a[1025], b[1025];
    scanf("%d %d", &n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d", &a[i]);
    for(int j=1;j<=m;j++)
        scanf("%d", &b[j]);
    int vmax=0, lin, col;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
            {
                int x=dp[i-1][j-1];
                int y=dp[i][j-1];
                int z=dp[i-1][j];
                dp[i][j]=max(max(x,y),z);
            }
            if(dp[i][j]>=vmax)
            {
                vmax=dp[i][j];
                lin=i;
                col=j;
            }
        }

    }
    int i=lin, j=col;
    while(dp[i][j]!=0)
    {
        if(a[i]==b[j])
        {
            sol[k++]=a[i];
            i--;
            j--;
        }
        else
        {
            if(dp[i][j-1]<dp[i-1][j])
                i--;
            else j--;
        }
    }
    printf("%d\n", k-1);
    for(int i=k-1;i>=1;i--)
    {
        //for(int j=1;j<=m;j++)
        printf("%d ", sol[i]);
        //printf("\n");
    }


    return 0;
}
