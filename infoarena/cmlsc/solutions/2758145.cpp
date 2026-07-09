#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int N = 1025;
int n, m, a[N], b[N], dp[N][N], ind, ans[N], ci, cj;

int main(){
    f >> n >> m;
    for(int i = 1; i <= n; i++)
        f >> a[i];

    for(int i = 1; i <= m; i++)
        f >> b[i];

    f.close();
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    g << dp[n][m] << '\n';
    ind = dp[n][m];
    ci = n;
    cj = m;
    while(dp[ci][cj] != 0){
        if(a[ci] == b[cj]){
            ans[ind--] = a[ci];
            ci--;
            cj--;
        }else{
            if(dp[ci - 1][cj] > dp[ci][cj - 1])
                ci--;
            else
                cj--;
        }
    }

    for(int i = 1; i <= dp[n][m]; i++)
        g << ans[i] << ' ';

    g.close();
}
