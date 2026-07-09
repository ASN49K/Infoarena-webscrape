# include <cstdio>
# include <algorithm>
# include <vector>
using namespace std;

FILE *f = freopen("cmlsc.in", "r", stdin);
FILE *g = freopen("cmlsc.out", "w", stdout);

const int N_MAX = 1050;

int v1[N_MAX], v2[N_MAX];
int dp[N_MAX][N_MAX];

int n, m;

vector <int> sol;

void solve()
{
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            if (v1[i] == v2[j])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    /*for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=m; j++)
        {
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }*/

    printf("%d\n", dp[n][m]);

    while (n && m)
    {
        if (v1[n] == v2[m])
        {
            sol.push_back(v1[n]); /// sau v2[m]

            n--;
            m--;
        }
        else
        {
            if (dp[n-1][m] > dp[n][m-1])
                n--;
            else
                m--;
        }
    }

    for (int i = sol.size() - 1; i>=0; i--)
        printf("%d ", sol[i]);
}

void read()
{
    scanf("%d %d", &n, &m);

    for (int i=1; i<=n; i++)
        scanf("%d", &v1[i]);

    for (int i=1; i<=m; i++)
        scanf("%d", &v2[i]);
}

int main()
{
    read();
    solve();
    return 0;
}
