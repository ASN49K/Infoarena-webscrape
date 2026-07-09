#include <cstdio>

using namespace std;

const int nmx = 1030;

int n,m;
int a[nmx], b[nmx];
int dp[nmx][nmx];

inline int max(const int &a, const int &b)
{
    return a > b ? a : b;
}

void citire()
{
    scanf("%d", &n);
    scanf("%d", &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d", &a[i]);
    for(int i = 1; i <= m; ++i)
        scanf("%d", &b[i]);
}

void dinamica()
{
    for(int i = 1; i <= m; ++i)
        for(int j = 1; j <= n; ++j)
            if(b[i] == a[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
}

void recursiv(int i, int j)
{
    if(dp[i][j] == 0)
        return;
    if(a[j] == b[i])
    {
        recursiv(i-1,j-1);
        printf("%d ", a[j]);
    }
    else if(dp[i-1][j] > dp[i][j-1] && i - 1 >= 0)
        recursiv(i-1,j);
    else
        recursiv(i,j-1);

}

void afish()
{
    printf("%d\n", dp[m][n]);
    recursiv(m,n);
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
