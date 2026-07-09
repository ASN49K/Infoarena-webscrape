#include <bits/stdc++.h>

using namespace std;
int dp[1025][1025];
int a[1025],b[1025];
vector <int> sol;
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n,m,i,j;
    cin >> n >> m;
    for(i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(i = 1;i <= m;i++){
        cin >> b[i];
    }
    for(i = 1;i <= n;i++){
        for(j = 1;j <= m;j++){
            if(a[i] == b[j]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    cout << dp[n][m] << "\n";
    i = n,j = m;
    while(i > 0 && j > 0){
        if(dp[i][j] == dp[i-1][j - 1] + 1){
            sol.push_back(b[j]);
            i--;
            j--;
        }else if(dp[i][j-1] < dp[i-1][j]){
            i--;
        }else{
            j--;
        }
    }
    for(i = sol.size() - 1;i >= 0;i--)
        cout << sol[i] << " ";
    return 0;
}
