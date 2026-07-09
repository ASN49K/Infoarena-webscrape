#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1030], b[1030], dp[1030][1030], f1[300], f2[300];
int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
        f1[a[i]] ++;
    }
    for(int i = 1; i <= m; i ++){
        cin >> b[i];
        f2[b[i]] ++;
    }
    for(int i = 0; i <= m; i ++){
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i ++){
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    sort(a, a + n + 1);
    sort(b, b + n + 1);
    cout << dp[n][m] << "\n";
    for(int i = 1; i <= 256; i ++){
        if(f1[i] > 0 && f2[i] > 0){
            cout << i << " ";
        }
    }
    return 0;
}
