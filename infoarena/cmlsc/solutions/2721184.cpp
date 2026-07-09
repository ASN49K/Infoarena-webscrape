#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int NMAX = 1025;
int n, m, a[NMAX], b[NMAX], dp[NMAX][NMAX];

void print(int i, int j, int k) {

    if(k == 0)
        return;

    if(a[i] == b[j]) {
        print(i - 1, j - 1, k - 1);
        g << a[i] << ' ';
    } else if(dp[i - 1][j] == k){
        print(i - 1, j, k);
    }else {
        print(i, j - 1, k);
    }
}

int main() {

    f >> n >> m;

    for(int i = 1;i <= n;++i)
        f >> a[i];

    for(int i = 1;i <= m;++i)
        f >> b[i];

    for(int i = 1;i <= n;++i)
        for(int j = 1;j <= m;++j)
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    g << dp[n][m] << '\n';

    print(n, m, dp[n][m]);

    return 0;
}
