#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
short int v[1025], w[1025];
short int dp[1025][1025];
short int res[1025];
int best;

int main() {

    fin>>n>>m;
    for (int i = 1; i <= n; i ++) {

        fin>> v[i];

    }

    for (int j = 1; j <= m; j ++) {

        fin>> w[j];

    }

    for (int i = 1; i <= n; i ++) {

        for (int j = 1; j <= m; j ++) {

            if (v[i] == w[j]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;

            } else {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

            }

        }

    }

    for (int i = n, j = m; i; ) {

        if (v[i] == w[j]) {

            res[++best] = v[i], --i, --j;

        } else if (dp[i - 1][j] < dp[i][j - 1]) {

            --j;

        } else {

            --i;

        }

    }

    fout<< best<< '\n';
    for (int i = best; i >= 1; i --) {

        fout<< res[i]<< ' ';

    }

    fin.close();
    fout.close();

}