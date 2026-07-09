#include <bits/stdc++.h>
using namespace std;

const string FILENAME = "cmlsc";
ifstream fin(FILENAME + ".in");
ofstream fout(FILENAME + ".out");

int n,m;
int a[1025], b[1025];
int dp[1025][1025], ans[1025];
int main()
{
    fin >> n >> m;

    for(int i = 1; i <= n; ++i)
        fin >> a[i];
    for(int i = 1; i <= m; ++i)
        fin >> b[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = max({dp[i - 1][j], dp[i][j - 1], (a[i] == b[j]) ? dp[i - 1][j - 1] + 1 : -1});
    fout << dp[n][m] << "\n";
    int i, j, p;
    i = n, j = m;
    p = 0;
    while(i && j)
    {
        if(a[i] == b[j])
        {
            ans[++p] = a[i];
            i--;
            j--;
        }
        else if(dp[i - 1][j] < dp[i][j - 1])
            j--;
        else i--;
    }
    reverse(ans + 1, ans + p + 1);
    for(int i = 1; i <= p; i++)
        fout << ans[i] << " ";
    fin.close();
    fout.close();
	return 0;
}
