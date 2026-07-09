#include <cstdio>
#include <algorithm>
#include <vector>

#define in "cmlsc.in"
#define out "cmlsc.out"
#define NMAX (1024 + 7)

using namespace std;
int m, n, v1[NMAX], v2[NMAX], dp[NMAX][NMAX], ct = 1;

int main()
{
    //freopen(in, "r", stdin);
    //freopen(out, "w", stdout);
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
    for(int i = 1; i<= m; ++i)
    {
        for(int j = 1; j<=  n; ++j)
        {
            if(dp[i][j] == ct)
            {
                ++ct;
                printf("%d ", v1[i]);
            }
        }
    }
    printf("\n");
    return 0;
}
