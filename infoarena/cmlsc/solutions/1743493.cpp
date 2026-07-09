#include <cstdio>
#include <algorithm>
#include <stack>

#define in "cmlsc.in"
#define out "cmlsc.out"
#define NMAX 1024 + 7

using namespace std;
int n, m, v[2][NMAX], dp[NMAX][NMAX];
stack <int> solution;

inline void read()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i<= n; ++i) scanf("%d ", &v[0][i]);
    for(int i = 1; i<= m; ++i) scanf("%d ", &v[1][i]);
}
inline void build_dynamic()
{
    for(int i = 1; i<= n; ++i)
    {
        for(int j = 1; j<= m; ++j)
        {
            if(v[0][i] == v[1][j])
            {
                dp[i][j] = dp[i-1][j-1] + 1;
                continue;
            }
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
}
inline void construct_sol()
{
    int px = n, py = m;
    while(px >= 1 && py >= 1)
    {
        int ct = 0;
        if(dp[px-1][py] == dp[px][py]) ct += 1;
        if(dp[px][py-1] == dp[px][py]) ct += 2;
        if(ct == 0)
        {
            solution.push(v[0][px]);
            px --;
            py --;
        }
        if(ct == 3)
        {
            if(dp[px-1][py-1] != dp[px][py])
            {
                ct = 1;
            }
            else
            {
                px --;
                py --;
            }
        }
        if(ct == 1) px --;
        if(ct == 2) py --;
    }
}
inline void output()
{
    printf("%d\n", dp[n][m]);
    while(!solution.empty())
    {
        printf("%d ", solution.top());
        solution.pop();
    }
}

int main()
{
    freopen(in, "r", stdin);
    freopen(out, "w", stdout);
    read();
    build_dynamic();
    construct_sol();
    output();
    return 0;
}
