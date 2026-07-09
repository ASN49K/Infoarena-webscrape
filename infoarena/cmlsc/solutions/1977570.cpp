#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define pb push_back
#define ll long long
const int NMax = 1050;
const int inf = 1e9 + 5;

int N,M,nrSol;
int a[NMax],b[NMax],dp[NMax][NMax],sol[NMax];

int main()
{
    in>>N>>M;
    for (int i=1;i <= N;++i) {
        in>>a[i];
    }

    for (int j=1;j <= M;++j) {
        in>>b[j];
    }

    for (int i=1;i <= N;++i) {
        for (int j=1;j <= M;++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                continue;
            }

            dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }

    out<<dp[N][M]<<'\n';
    int i = N, j = M;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            sol[++nrSol] = a[i];
            --i;
            --j;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        }
        else {
            --j;
        }
    }

    for (int i=nrSol;i > 0;--i) {
        out<<sol[i]<<' ';
    }

    in.close();out.close();
    return 0;
}
