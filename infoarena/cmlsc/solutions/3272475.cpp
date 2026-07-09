#include <bits/stdc++.h>
using namespace std;
struct de_pe{
    int val;
    vector<int> nr;
}dp[2][1030];
int v1[1030], v2[1030];
int main()
{
    ifstream cin("cmlsc.in");
    ofstream cout("cmlsc.out");
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v1[i];
    for(int i = 1; i <= m; i++)
        cin >> v2[i];
    for(int i = 1; i <= n; i++){
        int acc = i % 2;
        for(int j = 1; j <= m; j++){
            if(v1[i] == v2[j]){
                dp[acc][j].val = dp[1 - acc][j-1].val + 1;
                dp[acc][j].nr = dp[1 - acc][j - 1].nr;
                dp[acc][j].nr.push_back(v1[i]);
            }
            else{
                if(dp[1 - acc][j].val > dp[acc][j-1].val)
                    dp[acc][j] = dp[1 - acc][j];
                else
                    dp[acc][j] = dp[acc][j-1];
            }
        }
    }
    cout << dp[n % 2][m].val << '\n';
    for(auto i : dp[n%2][m].nr)
        cout << i << " ";
    return 0;
}