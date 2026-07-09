#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1050], b[1050];
int dp[1050][1050];

vector <int> sol;
void read() {
    fin >> m >> n;
    int i;
    for (i = 1; i <= m; ++i)
        fin >> a[i];
    for (i = 1; i <= n; ++i)
        fin >> b[i];
}

void solve() {
    int i, j;
    for (i = 1; i <= m; ++i)
        for (j = 1; j <= n; ++j)
        if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
        else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    i = m, j = n;
    fout << dp[i][j] << "\n";
    for (; i;) {
        if (a[i] == b[j]) sol.push_back(a[i]), i--, j--;
        else
            if (dp[i - 1][j] > dp[i][j - 1]) i--;
        else j--;
    }
    for (vector <int> :: reverse_iterator it = sol.rbegin(); it != sol.rend(); ++it)
        fout << *it << " ";
}
int main()
{
    read();
    solve();
    return 0;
}
