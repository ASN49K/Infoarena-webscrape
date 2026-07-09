#include <cstdio>
#include <algorithm>
#include <vector>

#define in "cmlsc.in"
#define out "cmlsc.out"
#define NMAX (1024 + 7)

using namespace std;
int m, n, v1[NMAX], v2[NMAX], dp[NMAX][NMAX], ct = 1;

void afisare(int x, int y)
{
    if(dp[x][y] == 0) return;
    if(dp[x-1][y-1] == dp[x][y])
    {
        afisare(x-1, y-1);
        return ;
    }
    if(dp[x-1][y-1] == dp[x][y]-1 && dp[x][y-1] == dp[x][y]-1 && dp[x-1][y] == dp[x][y]-1)
    {
        afisare(x-1, y-1);
        printf("%d ", v1[x]);
        return ;
    }
    if(dp[x][y-1] > dp[x-1][y])
    {
        afisare(x, y-1);
        return ;
    }
    afisare(x-1, y);
    return ;
}

int main()
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    scanf("%d %d", &m, &n);
    for(int i = 1; i<= m; ++i) scanf("%d", &v1[i]);
    for(int i = 1; i<= n; ++i) scanf("%d", &v2[i]);
    for(int i = 1; i<= m; ++i)
    {
        for(int j = 1; j<= n; ++j)
        {
            if(v1[i] == v2[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else  dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    printf("%d\n", dp[m][n]);
    afisare(m, n);
    printf("\n");
    return 0;
}
