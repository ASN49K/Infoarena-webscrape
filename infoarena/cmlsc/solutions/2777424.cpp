#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
const int NMAX = 1 << 10;
int a[NMAX + 5], b[NMAX + 5], dp[NMAX + 5][NMAX + 5];

int main()
{
    int n, m;
    fin >> n >> m;
    for(int i = 1; i <= n; i++) fin >> a[i];
    for(int i = 1; i <= m; i++) fin >> b[i];
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            dp[i][j] = a[i] == b[j] ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
    fout << dp[n][m] << "\n";
    int i = n, j = m;
    vector <int> sol;
    while(i && j) {
        if(a[i] == b[j]) sol.push_back(a[i]), i--, j--;
        else if(dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    reverse(sol.begin(), sol.end());
    for(int i = 1; i <= dp[n][m]; i++) fout << sol[i - 1] << " ";
    return 0;
}
