#include <bits/stdc++.h>
using namespace std;
#define mod                1000000007
#define ll                 long long 
#define all(v)             v.begin(), v.end()
#define fr(n)              for(ll i=0;i<n;++i)
#define ctz(x)             __builtin_ctzll(x)
#define clz(x)             __builtin_clzll(x)
#define pcount(x)          __builtin_popcountll(x)
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
#define cin fin
#define cout fout
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
 
 

void solve(){
    ll n, m;cin>>n>>m;
	ll v[n+1], v2[m+1];
    for(ll i=1; i<=n; i++){
    	cin>>v[i];
	}
	for(ll i=1; i<=m; i++){
		cin>>v2[i];
	}
	ll dp[n+1][m+1];
	memset(dp, 0, sizeof(dp));
	for(ll i=1; i<=n; i++){
		for(ll j=1; j<=m;j++){
			if(v[i]==v2[j]) dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
		}
	}
	cout<<dp[n][m]<<"\n";
	ll temp=dp[n][m];
	ll i=n, j=m;
	vector<ll> a;
	while(i>0 && j>0){
	 	if(dp[i-1][j]==temp) i--;
	 	else if(dp[i][j-1]==temp) j--;
	 	else{
	 		a.push_back(v[i]);i--;j--;temp--;
		 }
	}
	reverse(all(a));
	fr(a.size()) cout<<a[i]<<" ";
	
}
 
 
int main(){
//   ios_base::sync_with_stdio(false); cin.tie(NULL);
//   ll t;cin>>t;while(t--){solve();cout<<endl;}
	solve();
}
