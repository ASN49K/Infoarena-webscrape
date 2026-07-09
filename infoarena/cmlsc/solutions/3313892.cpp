#include <fstream>

using namespace std;
int v[1030], u[1030], dp[1030][1030];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    for(int i = 1; i <= m; i++){
        cin >> u[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(v[i] == u[j]){
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(dp[i][j] == dp[i - 1][j - 1] + 1  &&  v[i] == u[j]){
                cout << v[i] << " ";
            }
        }
    }
    return 0;
}
