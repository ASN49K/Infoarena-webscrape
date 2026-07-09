#include <bits/stdc++.h>
using namespace std;

int a[10005], b[10030], dp[1030][1030], sol[100005];
int main(void){
    ofstream cout("cmlsc.out");
    ifstream cin("cmlsc.in");
    int n, m,maxim = -1;
    cin >> n >> m;
    for(int i = 1;i<=n;i++)cin >> a[i];
    for(int j = 1;j<=m;j++)cin >> b[j];
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i] == b[j]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            maxim = max(maxim, dp[i][j]);
        }
    }
    int i = n, j = m;
    int k = 0;
    cout << maxim << '\n';
    while(i >= 1 && j >= 1){
        if(a[i] == b[j]){
            sol[++k] = a[i];
            i--;
            j--;
        }else{
            if(dp[i-1][j] >= dp[i][j-1]){
                i--;
            }else{
                j--;
            }
        }
    }
    for(int i = k;i>=1;i--){
        cout << sol[i] << ' ';
    }
}