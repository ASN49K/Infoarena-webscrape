#include <fstream>
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX 1025

using namespace std;

int dp[MAX][MAX];
int v1[MAX], v2[MAX];

int main() {
    int n, m, i, j;

    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    fin >> n >> m;

    for (i = 1; i<=n; ++i)
        fin >> v1[i];

    for (i = 1; i<=m; ++i)
        fin >> v2[i];

    for (i = 1; i<=n; ++i) {
        for (j = 1; j<=m; ++j) {
            if (v1[i] == v2[j]) {
                dp[i][j] = dp[i-1][j-1]+1;
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    vector<int> traceback;

    i = n;
    j = m;

    while(i != 0) {
        if (v1[i] == v2[j]) {
            traceback.push_back(v1[i]);
            --i;
            --j;
        } else if (dp[i-1][j] < dp[i][j-1])
            --j;
        else
            --i;
    }

    fout << dp[n][m] << '\n';

    for (i = traceback.size()-1; i>=0; --i)
        fout << traceback[i] << ' ';

    return 0;
}
