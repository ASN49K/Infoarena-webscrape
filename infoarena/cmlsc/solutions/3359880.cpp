/*  
    *
    * soon on twitch : ex3qute 
    * 
    * ax ah al
    * kwxkwxkxkxwkxkwxkw
    * dumnezeu sa o ierte
*/


#include <bits/stdc++.h>  
using namespace std;  
#define ull unsigned long long  
#define ll long long  
#define pb push_back  
#define fastio ios_base::sync_with_stdio(0); cin.tie(nullptr);  
const int MOD = 1e9+7;
int di[4]={0,0,-1,1};  
int dj[4]={-1,1,0,0};  

const string FILENAME = "cmlsc";
ifstream f(FILENAME + ".in");
ofstream g(FILENAME + ".out");
#ifndef exe
#define cin f
#define cout g
#endif


int dp[1025][1025];

signed main(){   
    

    int n,m;
    cin >> n >> m;
    vector<int> a(n+1), b(m+1);
    for(int i=1;i<=n;++i) cin >> a[i];
    for(int i=1;i<=m;++i) cin >> b[i];
    

    for(int i=1;i<=n;++i) {
        for(int j=1;j<=m;++j) {
            if(a[i] == b[j]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }


    vector<int> ans;

    for(int i=n,j=m;i && j;) {
        if(a[i] == b[j]) {
            ans.pb(i);
            i--,j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]) {
            i--;
        }
        else j--;
    }

    sort(ans.begin(), ans.end());

    cout << dp[n][m] << '\n';
    for(auto idx : ans) cout << a[idx] << ' ';
    
    return 0;
}


