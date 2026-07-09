#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define endl "\n"
 
const int Nmax = 1100;
const int MODULO = 1e9 + 7;
const int oo = -1e9;

int n, m;
int a[Nmax], b[Nmax];
int dp[Nmax][Nmax];

void solve() {
	cin >> m >> n;
	for(int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for(int j = 1; j <= n; j++) {
		cin >> b[j];
	}
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) {
			if(a[i] == b[j]) {
				dp[i][j] = 1 + dp[i - 1][j - 1];
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	cout << dp[m][n] << endl;
	int ci = m;
	int cj = n;
	int contor = dp[m][n];
	vector < int > sol;
	while(contor) {
		if(a[ci] == b[cj]) {
			sol.push_back(a[ci]);
			ci--;
			cj--;
			contor--;
		} else {
			if(dp[ci - 1][cj] > dp[ci][cj - 1]) {
				ci--;
			} else {
				cj--;
			}
		}
	}
	reverse(sol.begin(), sol.end());
	for(auto it : sol) {
		cout << it << " ";
	}
}
	
void fisier() {
	freopen("cmlsc.in" , "r", stdin);
	freopen("cmlsc.out", "w", stdout);
}

 
int main() {
	ios_base::sync_with_stdio(0);
 
	cin .tie(0);
	cout.tie(0);

	fisier();
 
	int testCases = 1;
	//cin >> testCases;
	while(testCases--) {
		solve();
	}
}