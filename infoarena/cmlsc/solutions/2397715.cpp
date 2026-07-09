#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define rc(x) return cout<<x<<endl,0
#define pb push_back
#define dbg(x) cout << #x << '=' << x << '\n';
#define ll long long
#define sz size()
#define x first
#define y second
#define pi pair <int, int>
#define pii pair <pi, pi>
#define vi vector <ll>
#define in insert
#define er erase
#define fd find
int n, m, v1[1025], v2[1025];
int dp[1025][1025];
vector <int> ans;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cerr.tie(0);cout.tie(0);
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
    cin>>n>>m;
    for(int i=1; i<=n; i++) cin>>v1[i];
    for(int j=1; j<=m; j++) cin>>v2[j];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            dp[i][j]=max(max(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]+(v1[i]==v2[j]));
        }
    }
    /*for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout<<dp[n][m]<<'\n';
    int i=n, j=m;
    while(i && j){
        if(dp[i][j]==dp[i-1][j-1]+1){
            ans.pb(v1[i]);
            i--, j--;
        }
        else if(dp[i][j-1]<dp[i-1][j]) i--;
        else j--;
    }
    reverse(ans.begin(), ans.end());
    for(int i: ans) cout<<i<<" ";
}
