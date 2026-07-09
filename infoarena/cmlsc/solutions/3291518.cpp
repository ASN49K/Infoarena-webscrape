#include <fstream>
#include <iostream>

using namespace std;

const int N = (1 << 10) + 5;
int n, m, a[N], b[N];
int dp[N][N];

    ofstream fout("cmlsc.out");
void afisatiune(int i, int j, int k) {
    if (!k)return;
    if (a[i] == b[j]) { afisatiune(i - 1, j - 1, k - 1), fout << a[i] << ' '; return; }
    if (dp[i - 1][j] > dp[i][j - 1])afisatiune(i - 1, j, k);
    else afisatiune(i, j - 1, k);
}

int main()
{
    int i, j;
    ifstream fin("cmlsc.in");
    fin >> n >> m;
    for (i = 1; i <= n; i++)fin >> a[i];
    for (i = 1; i <= m; i++)fin >> b[i];
    for (i = 1; i <= n; i++)for (j = 1; j <= m; j++)dp[i][j] = a[i]==b[j]?dp[i - 1][j - 1] + 1:max(dp[i-1][j],dp[i][j-1]);
    i = n, j = m;

    fout << dp[n][m]<<'\n';
    afisatiune(n, m, dp[n][m]);
    fout.close();
    return 0;
}