#include <stdio.h>
#define MAX 1027
using namespace std;

int a[MAX], b[MAX], dp[MAX][MAX], n, m, choose[MAX][MAX];

void read()
{
    int i;

    scanf("%d %d", &n, &m);

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <= n; i++)
        scanf("%d",&b[i]);

}



void out(int i, int j)
{
    if(i && j)
    {
        if(choose[i][j] == 1)
        {
            out(i - 1, j - 1);
            printf("%d ",a[i]);
        }
        else
            if(choose[i][j] == 2)
             out(i - 1, j);
        else
            out(i,j - 1);
    }
}



void solve()
{
    int i,j;

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            if(a[i] == b[j])
             {
                 dp[i][j] = dp[i - 1][j - 1] + 1;
                 choose[i][j] = 1;
             }
            else
                if(dp[i - 1][j] >= dp[i][j - 1])
                {
                         dp[i][j] = dp[i - 1][j];
                         choose[i][j] = 2;
                }
            else
                {
                    dp[i][j] = dp[i][j - 1];
                    choose[i][j] = 3;
                }
}


int main()
{
    freopen("cmlsc.in","r",stdin);
    freopen("cmlsc.out","w",stdout);

    read();

    solve();

    printf("%d\n",dp[n][m]);

    out(n,m);

    return 0;
}
