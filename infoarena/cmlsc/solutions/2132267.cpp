#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int N = 1026;
int a[N], b[N], dp[N][N], af[N];
void solve(int n, int m){
    int cnt = 0, x = n, y = m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++){
            if(a[i] == b[j])
                dp[i][j] = 1 + dp[i-1][j-1];
            else{
                dp[i][j] = dp[i-1][j];
                if(dp[i][j] < dp[i][j-1])
                    dp[i][j] = dp[i][j-1];
            }
        }
    out<<dp[n][m]<<"\n";
    while(x > 0 && y > 0){
        if(a[x] == b[y]){
            af[++cnt] = a[x];
            x--;
            y--;
        }
        else if(dp[x-1][y] < dp[x][y-1])
            y--;
        else
            x--;
    }
    for(int i=cnt;i>=1;i--)
        out<<af[i]<<" ";
    out<<"\n";
}
int main()
{
    int n,m;
    in>>n>>m;
    for(int i=1;i<=n;i++)
        in>>a[i];
    for(int i=1;i<=m;i++)
        in>>b[i];
    in.close();
    solve(n,m);
    out.close();
    return 0;
}
