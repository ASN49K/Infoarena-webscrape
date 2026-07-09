#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMax = 1e3 + 50;

int N,M,nrSol;
short a[NMax],b[NMax],dp[NMax][NMax],sol[NMax];

int main() {
    in>>N>>M;
    for (int i=1;i<=N;++i) {
        in>>a[i];
    }
    for (int j=1;j<=M;++j) {
        in>>b[j];
    }

    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                continue;
            }

            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    out<<dp[N][M]<<'\n';

    int i,j;
    i = N; j = M;
    while (i>0 && j>0) {
        if (a[i] == b[j]) {
            sol[++nrSol] = a[i];
            --i; --j;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        }
        else {
            --j;
        }
    }

    while (nrSol) {
        out<<sol[nrSol--]<<' ';
    }

    return 0;
}
