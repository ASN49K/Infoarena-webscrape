#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define ll long long
#define ull unsigned long long
#define pb push_back
#define mp make_pair
const int NMax = 2e3 + 5;
const int inf = 1e9 + 5;

int N,M;
int a[NMax],b[NMax],dp[NMax][NMax],sol[NMax];

int main() {
    in>>N>>M;
    for (int i=1;i <= N;++i) {
        in>>a[i];
    }
    for (int i=1;i <= M;++i) {
        in>>b[i];
    }

    for (int i=1;i <= N;++i) {
        for (int j=1;j <= M;++j) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }

    int i=N,j=M;
    while (i > 0 && j > 0) {
        if (a[i] == b[j]) {
            sol[++sol[0]] = a[i];
            --i;--j;
        }
        else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        }
        else {
            --j;
        }
    }

    out<<dp[N][M]<<'\n';
    for (int i=sol[0];i > 0;--i) {
        out<<sol[i]<<' ';
    }

    in.close();out.close();
    return 0;
}

