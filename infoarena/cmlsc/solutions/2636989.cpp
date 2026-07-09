#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;

const ll mod=1e9+7;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define rc(x)  return cout<<x<<"\n",0
#define sz(s)  (int) s.size()
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;

ll t;

int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	ll n,m;
	cin >> n >> m;
	ll a[n+5],b[m+5],dp[n+2][m+2];
	for (int i=0; i<=m; i++) {
		for (int j=0; j<=n; j++) {
			dp[i][j]=0;
		}
	}

	for (int i=1; i<=n; i++)cin>>a[i];
	for (int i=1; i<=m; i++)cin>>b[i];
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n;j++) {
			dp[i][j]=max(dp[i-1][j],dp[i][j-1])+(a[j]==b[i]);
		}
	}
	vector<int>ans;
	ll maxx=-2e18;
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			if (dp[i][j]>dp[i-1][j] && dp[i][j]>dp[i][j-1] && dp[i][j]>maxx) {
				ans.pb(a[j]);
				maxx=dp[i][j];
			}
		}
	}
	cout << maxx << '\n';
	for (auto it:ans) {
		cout << it << " ";
	}
	

}

