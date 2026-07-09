#include <fstream>
#include <vector>

using namespace std;
int v[1030], u[1030], dp[1030][1030];
vector <int> afis;
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m, k;
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
    k = dp[n][m];
    int l = n, c = m;
    while(k > 0){
        if(v[l] == u[c]  &&  dp[l][c] == k){
            afis.push_back(v[l]);
            l--;
            c--;
            k--;
        }else{
            if(dp[l - 1][c] == k){
                l--;
            }else{
                c--;
            }
        }
    }
    for(int i = dp[n][m] - 1; i >= 0; i--){
        cout << afis[i] << " ";
    }
    return 0;
}
