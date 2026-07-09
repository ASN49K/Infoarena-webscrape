#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define nmax 1<<9+1
using namespace std;

short dp[nmax][nmax];
short a[nmax], b[nmax];


int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	int n, m, i, j;

	f>>n>>m;
	for(i=1; i<=n; i++) f>>a[i];
	for(i=1; i<=m; i++) f>>b[i];

	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) {
			if(a[i]==b[j])
				dp[i][j] = dp[i-1][j-1] + 1;
			else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
		}

	g<<dp[n][m]<<"\n";
	for(j=1; j<=m; j++) if(dp[n][j] && dp[n][j] > dp[n][j-1]) g<<b[j]<<" ";

	return 0;
}
