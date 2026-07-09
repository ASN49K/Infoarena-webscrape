#include<cstdio>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<bitset>
#include<deque>
#include<queue>
#include<set>
#include<map>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<unordered_map>

#define ll long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

const int nmax = 1030;

int n, m, i, j, mlc, p, dp[nmax][nmax], a[nmax], b[nmax], sol[nmax];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &n, &m);

    for(i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for(i = 1; i <= m; i++)
        scanf("%d", &b[i]);

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
        {
            mlc = (a[i] == b[j]) ? 1 : 0;
            dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + mlc);
        }

    printf("%d\n", dp[n][m]);

    for(i = n, j = m; p < dp[n][m];)
    {
        if(a[i] == b[j]) sol[++p] = a[i], i--, j--;
        else if(dp[i][j] == dp[i - 1][j])  i--;
        else j--;
    }

    for(i = p; i >= 1; i--)
        printf("%d ", sol[i]);

    return 0;
}
