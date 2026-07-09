#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025];
int b[1025];
int dp[1025][1025];

vector<int> rez;

int main()
{
    int m, n;
    fin >> m >> n;

    for (int i = 1; i <= m; i++) {
        fin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        fin >> b[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[j] == b[i])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    fout << dp[n][m] << '\n';

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {
        if (b[i] == a[j]) {
            rez.push_back(b[i]);
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }

    for (int i = rez.size() - 1; i >= 0; i--) {
        fout << rez[i] << " ";
    }

    return 0;
}
