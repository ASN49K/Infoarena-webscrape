#include <fstream>
#include <cmath>

using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

int dp[1100][1100];
int main(){
    int n , m;
    int a[1100] , b[1100];
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= m; i++)
        cin >> b[i];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if (a[i] == b[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j] , dp[i][j - 1]);
        }
    }
    cout << dp[n][m];
    for(int i = 1; i <= n; i++ , cout << '\n')
        for(int j = 1; j <= m; j++)
            cout << dp[i][j] << ' ';
    int sir[1100];
    int k = 0;
    int i = n , j = m;
    while (i > 1 and j > 1){
        if (dp[i][j] == dp[i - 1][j]){
            sir[++k] = a[i - 1];
            i--;
        }
        else if(dp[i][j] == dp[i][j - 1]){
            sir[++k] = a[j - 1];
            j--;
        }
        else if (dp[i][j] - 1 == dp[i - 1][j - 1]){
            sir[++k] = a[i];
            i--;
            j--;
        }
        else
            j--;
    }
    cout << '\n';
    for(int ii = k; ii > 0; ii--)
        cout << sir[ii] << ' ';
    
}