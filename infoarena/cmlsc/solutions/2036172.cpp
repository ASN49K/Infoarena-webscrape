#include<fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int INF = 1e9;
int n,m,dp[1025][1025],a[1025],b[1025],rez[1025],k;
int main(){
    in >> n >> m;
    for (int i = 1; i <= n; i ++) {
        in >> a[i];
    }
    for (int i = 1; i <= m; i ++) {
        in >> b[i];
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            dp[i][j] = -INF;
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= m; j ++) {
            if (a[i] == b[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else{
                dp[i][j] = max (dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    out << dp[n][m]<<"\n";
    k = dp[n][m];
    for (int i = n; i >= 1; i --) {
        for (int j = m; j >= 1; j --) {
            if (a[i] == b[j] && dp[i][j] == k) {
                rez[k] = a[i];
                k--;
            }
        }
    }
    for (int i = 1; i <= dp[n][m]; i ++) {
        out << rez[i] <<" ";
    }
    return 0;
}
