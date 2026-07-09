#include <iostream>
#include <fstream>
using namespace std;
int n, m, dp[1001][1001], s[1001], v[1001], ananas, ananas2[1001];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1;i <= m;i++)
        cin >> s[i];
    for (int i = 1;i <= n;i++)
        for (int j = 1;j <= m;j++) {
            if (v[i] == s[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    ananas = dp[n][m];
    int aux = ananas;
    cout << ananas << '\n';
    while (ananas) {
        if (v[n] == s[m])
        {
            ananas2[ananas] = v[n];
            ananas--;
            n--;
            m--;
        }
        else if (dp[n][m - 1] == dp[n][m])
        {
            m--;
        }
        else n--;
    }
    for (int i = 1;i <= aux;i++)
        cout << ananas2[i] << " ";
}
