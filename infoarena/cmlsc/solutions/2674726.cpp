#include <iostream>
#include <fstream>
using namespace std;
 
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

#define N  1025
#define MAX(a, b) ((a) > (b) ? (a) : (b))

int main(){

    int n, m;
    int x[N];
    int y[N];

    in >> n >> m;
    int dp[N][N];

    int nr;

    for (int i = 0; i < n; i++) {
        in >> x[i];
       // printf("[%d] ", x[i]);
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        in >> y[i];
       // printf("[%d] ", y[i]);
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if(i == 0 || j == 0) {
                dp[i][j] = 0;
                continue;
            }

            if(x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]);
            }
           // printf("%d ", dp[i][j]);
        }
       // printf("\n");
    }

    // cout << dp[n][m] << endl;

    int len = dp[n][m];
    out << len << "\n";

    int res[N];

    int i = n;
    int j = m;
    int len2 = len;

   //  cout << "====\n";

    while(i > 0 && j > 0) {
        int crt = dp[i][j];
        int sus = dp[i][j - 1];
        int stanga = dp[i - 1][j];
        int stanga_sus = dp[i - 1][j - 1];
        if (crt > sus && crt > stanga) {
            res[--len] = x[i - 1];
            // cout << x[i - 1];
            i--;
            j--;
        } else {
            if(crt == sus) {
                j--;
            } else {
                i--;
            }
        }
    }

    for(int i = 0; i < len2; i++) {
        out << res[i] << " ";
    }


}