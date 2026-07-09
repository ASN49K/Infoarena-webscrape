#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMax = 1e3 + 30;

int N,M,nrSol;
int a[NMax],b[NMax],sol[NMax];
int dp[NMax][NMax];

int main() {
    in>>N>>M;
    for (int i=1;i<=N;++i) {
        in>>a[i];
    }
    for (int i=1;i<=M;++i) {
        in>>b[i];
    }

    for (int i=1;i<=N;++i) {
        for (int j=1;j<=M;++j) {

            if (a[i]==b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=N,j=M;
    while (dp[i][j]!=0) {
        if (a[i]==b[j]) {
            sol[++nrSol] = a[i];
            --i;--j;
        }
        else if (dp[i-1][j]>dp[i][j-1]) {
            --i;
        }
        else {
            --j;
        }
    }

    out<<nrSol<<'\n';
    for (int i=nrSol;i>0;--i) {
        out<<sol[i]<<' ';
    }
    return 0;
}
