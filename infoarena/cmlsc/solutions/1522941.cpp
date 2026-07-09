///Optimizare short int si char

#include <cstdio>
#include <algorithm>

#define NMAX 1037
#define in "cmlsc.in"
#define out "cmlsc.out"

using namespace std;
int n1, n2, v1[NMAX], v2[NMAX], dp[NMAX][NMAX];

inline void dinamica()
{
    for(int i = 1; i<= n1; ++i)
    {
        for(int j = 1; j<= n2; ++j)
        {
            if(v1[i] == v2[j]) {dp[i][j] = dp[i-1][j-1]+1; continue;}
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
void reconstituire(const int &x, const int &y)
{
    if(dp[x][y] == 0) return ;
    if(dp[x-1][y-1]  == dp[x][y])
    {
        reconstituire(x-1, y-1);
        return ;
    }
    if(dp[x-1][y] > dp[x][y-1])
    {
        reconstituire(x-1, y);
        return ;
    }
    if(dp[x][y-1] > dp[x-1][y])
    {
        reconstituire(x, y-1);
        return ;
    }
    if(dp[x-1][y-1] == dp[x][y] - 1)
    {
        reconstituire(x-1, y-1);
        printf("%d ", v1[x]);
        return ;
    }
}

int main()
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    scanf("%d %d", &n1, &n2);
    for(int i = 1; i<= n1; ++i) scanf("%d", &v1[i]);
    for(int i = 1; i<= n2; ++i) scanf("%d", &v2[i]);
    dinamica();
    printf("%d\n", dp[n1][n2]);
    reconstituire(n1, n2);
    printf("\n");
    return 0;
}
