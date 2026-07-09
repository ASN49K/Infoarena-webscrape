#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define inf 1e18
#define sz size()
#define x first
#define y second
#define pi pair <int, int>
#define pii pair <pi, pi>
#define vi vector <int>
const ll mod = 1e9 + 7;
int n, m;
int a[1030], b[1030];
int dp[1030][1030];
int viz[1030];

    ifstream in("cmlsc.in");
    ofstream out("cmlsc.out");

int32_t main(){

    in>>n>>m;
    for(int i=1; i<=n; i++) in>>a[i];
    for(int i=1; i<=m; i++) in>>b[i];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[i]==b[j])
                dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
        }
    }
    out<<dp[n][m];
    int i=n, j=m;
    while(i && j){
        if(dp[i][j]>max(dp[i-1][j], dp[i][j-1])){
            viz[i]=1;
            i--; j--;
        } else if(dp[i-1][j]>dp[j-1][i]) i--;
        else j--;
    }
    out<<'\n';
    for(int i=1; i<=n; i++){
        if(viz[i]) out<<a[i]<<" ";
    }
}
