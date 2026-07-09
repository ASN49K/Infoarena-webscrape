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
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second

using namespace std;

const int nmax = 1030;

int n, m, i, j, cnt, a[nmax], b[nmax], sol[nmax], dp[nmax][nmax];

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
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }

    printf("%d\n", dp[n][m]);
    for(i = n, j = m; i && j;)
    {
        if(a[i] == b[j])
            sol[++cnt] = a[i], i--, j--;
        else if(dp[i][j] == dp[i - 1][j])
            i--;
        else
            j--;
    }

    for(i = cnt; i; i--)
        printf("%d ", sol[i]);

    return 0;
}
