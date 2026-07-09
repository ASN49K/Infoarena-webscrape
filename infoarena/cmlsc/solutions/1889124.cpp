#include <iostream>
#include <cstdio>

using namespace std;

const int nmx = 1030;

int n,m,v1[nmx],v2[nmx],dp[nmx][nmx];

void citire()
{
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &v1[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &v2[i]);
}

void dinamica()
{
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
             if(v1[i] == v2[j])
                 dp[i][j] = dp[i-1][j-1] + 1;
             else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
}

void recursiv(int i, int j)
{
    if(not i || not j)
        return;

    if(v1[i] == v2[j])
    {
        recursiv(i-1,j-1);
        printf("%d ", v1[i]);
        return;
    }

    if(dp[i-1][j] > dp[i][j-1] && i > 1)
        recursiv(i-1,j);
    else
        recursiv(i,j-1);
}

void afish()
{
    printf("%d\n", dp[n][m]);
    recursiv(n,m);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    citire();
    dinamica();
    afish();
    return 0;
}
