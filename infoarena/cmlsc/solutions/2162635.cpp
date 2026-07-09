#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
#define N_MAX 1030
int a[N_MAX], b[N_MAX], dp[N_MAX][N_MAX], n, m;
vector <int> v;
void recur(int i, int j)
{
    if(i > 0 && j > 0 && a[i] == b[j])
    {
        v.push_back(a[i]);
        recur(--i, --j);
    }
    else if(i > 0 && (j == 0 || dp[i - 1][j] > dp[i][j - 1]))
        recur(--i, j);
    else if(j > 0 && (i == 0 || dp[i][j - 1] >= dp[i - 1][j]))
        recur(i, --j);
}
int main()
{
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];
    for(int i = 1; i <= m; i++)
        f >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            if(a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    g << dp[n][m] << "\n";
    recur(n, m);
    for(int i = v.size() - 1; i >= 0; i--)
        g << v[i] << " ";
    return 0;
}
