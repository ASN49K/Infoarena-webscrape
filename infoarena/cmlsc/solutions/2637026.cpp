#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

typedef long long ll;

const ll mod=1e9+7;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int nmax=1025;
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
ll a[nmax],b[nmax],dp[nmax][nmax];
int main() {
ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ifstream cin("cmlsc.in");
	ofstream cout("cmlsc.out");
	int n,m;
	cin >> n >> m;
	for (int i=1; i<=n; i++)cin>>a[i];
	for (int i=1; i<=m; i++)cin>>b[i];
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			if (a[j]==b[i]) {
				dp[i][j]=(dp[i-1][j-1]+1);
			}
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	vector<int>ans;
	int maxx=0;
	int i=m,j=n;
	while (j>0&&i>0) {
	 	if (a[j]==b[i]) {
	 		ans.pb(a[j]);
	 		i--;
	 		j--;
		 }
		 else {
		 	if (dp[i][j]>dp[i][j-1])i--;
			else j--; 	
		 }
		 
	}
	reverse(ans.begin(),ans.end());
	cout << dp[m][n] << '\n';
	for (auto it:ans) {
		cout << it << " ";
	}

/*	for (int i=1; i<=m; i++) {
		for (int j=1; j<=n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
*/

}

