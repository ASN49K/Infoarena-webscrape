#include <bits/stdc++.h>
using namespace std;
const int nmax = 1024;

int a[nmax+5];
int b[nmax+5];
int dp[nmax+5][nmax+5];

int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	int n,m; f >> n >> m;
	for(int i=1; i<=n; i++) f >> a[i];
	for(int i=1; i<=m; i++) f >> b[i];
	
	for(int i=1; i<=n; i++)
		for(int j=1; j<=m; j++)
			dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + (a[i]==b[j]));
	
	int i = n;
	int j = m;
	vector<int> sol;
	while(i and j) a[i]==b[j] ? sol.emplace_back(a[i]), i--, j-- : (dp[i-1][j]<dp[i][j-1] ? j-- : i--);
	reverse(sol.begin(),sol.end());
	g << dp[n][m] << "\n";
	for(auto i : sol) g << i << " ";
	return 0;
}
