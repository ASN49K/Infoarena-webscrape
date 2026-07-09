#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int N = 1025;
int n, m, a[N], b[N], dp[N][N], ind = 1;

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
    for(int i = 1; i <= n && ind <= dp[n][m]; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == ind){
                ind++;
                g << a[i] << ' ';
            }
        }
    }

    g.close();
}
