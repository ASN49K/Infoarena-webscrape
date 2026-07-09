#include <cstdio>
#include <algorithm>

using namespace std;

int n, m, a[1030], b[1030], dp[1030][1030], sol[1030];

int main()
{

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for(int i=1; i<=m; i++)
        scanf("%d", &a[i]);
    for(int i=1; i<=n; i++)
        scanf("%d", &b[i]);

    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i] == b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
        }
    }

    for(int i=m; i>=1; )//i--)
    {
        for(int j=n; j>=1; )//j--)
        {
            //if(i == j)
            if(a[i] == b[j])
            {
               sol[++sol[0]]=a[i];
               i--;
               j--;
            }
            else
            {
                if(dp[i-1][j]>dp[i][j-1])
                    i--;
                else
                    j--;
            }
            if(dp[i][j] == 0)
            {
                i=0;
                j=0;

            }
        }
    }
    printf("%d\n", sol[0]);
    for(int i=sol[0]; i>=1; i--)
        printf("%d ", sol[i]);
    return 0;
}
