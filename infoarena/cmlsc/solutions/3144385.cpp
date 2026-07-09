#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], dp[1025][1025], n, m;

int main() {
    fin >> m >> n;
    for (int i = 1; i <= m; i++)
        fin >> a[i];
    for (int i = 1; i <= n; i++)
        fin >> b[i];
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    int i = m, j = n, afis[1025], nr = 0;
    while (i)
        if (a[i] == b[j]) {
            afis[++nr] = a[i];
            i--, j--;
        }
        else if (dp[i - 1][j] < dp[i][j - 1])
            j--;
        else
            i--;
    fout << nr << "\n";
    for (int i = nr; i > 0; i--)
        fout << afis[i] << " ";
    return 0;
}
