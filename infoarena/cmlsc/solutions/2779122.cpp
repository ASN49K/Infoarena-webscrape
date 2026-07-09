#include <iostream>
#include <cstring>
#include <fstream>
#define dim 1030
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[dim], b[dim];
int dp[dim][dim];

void cmlsc(int i, int j) {

    if (i == 0 || j == 0) {
        return;
    }

    if (a[i] == b[j]) {
        cmlsc(i - 1, j- 1);
        out << a[i] << " ";
        return;
    }
    
    if (dp[i][j - 1] > dp[i - 1][j]) {
        cmlsc(i, j - 1);
    } else {
        cmlsc(i- 1, j);
    }
    
}

int main()
{
    int n, m, i, j;
    in >> n >> m;
    for(i = 1; i <= n; i++) {
        in >> a[i];
    }
    for(i = 1; i <= m; i++) {
        in >> b[i];
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }

    // for (i = 1; i <= n; i++) {
    //     for (j = 1; j <= m; j++) {
    //         out << dp[i][j] << " ";
    //     }
    //     out << '\n';
    // }
	out<<dp[n][m]<<"\n";
	cmlsc(n, m);
    
    out << '\n';

    return 0;
}