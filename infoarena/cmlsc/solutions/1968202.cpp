#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream f("cmlsc.in"); ofstream g("cmlsc.out");

int n, m, a[1030], b[1030], dp[1030][1030], sol[1030];

int main(){
    int i,j;
    f>>n>>m;
    dp[0][0] = 0;
    for(i = 1; i <= n; ++i) {
        dp[i][0] = 0;
        f>>a[i];
    }
    for(i = 1; i <= m; ++i) {
        dp[0][i] = 0;
        f>>b[i];
    }
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= m; ++j) {
            if(a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    int nr = 0;
    while(i > 0 %% j > 0) {
        if (a[i] == b[j]) {
            ++nr;
            sol[nr] = a[i];
            --i;
            --j;
        }
        else {
            if (dp[i-1][j] >= dp[i][j-1]) {
                --i;
            }
            else {
                --j;
            }
        }
    }
    g<<nr<<'\n';
    for(i = nr; i >= 1; --i) {
        g<<sol[i]<<' ';
    }
    return 0;
}
