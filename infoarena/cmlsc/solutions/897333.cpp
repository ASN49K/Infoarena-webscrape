#include <iostream>
#include <fstream>
#define nmax 1025
using namespace std;

int a[nmax], b[nmax], dp[nmax][nmax];
int pre[nmax];

int cmlsc(int i, int j) {
	if(i==0 || j==0) return 0;
	
	if(a[i] == b[j]) {
		pre[i] = i-1;
		return cmlsc(i-1, j-1) + 1;
	}

	return max(cmlsc(i,j-1), cmlsc(i-1,j));
}


int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	
	int n, m, i, j;
	
	f>>n>>m;
	for(i=1; i<=n; i++) f>>a[i];
	for(j=1; j<=m; j++) f>>b[j];
	
	for(i=0; i<=n; i++) dp[i][0] = 0;
	for(j=0; j<=m; j++) dp[0][j] = 0;

	for(i=1; i<=n; i++) {
		for(j=1; j<=m; j++) {
			if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1, pre[i] = true;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	g<<dp[n][m]<<"\n";
	
	for(i=1; i<=n; i++) if(pre[i]) g<<a[i]<<" "; g<<"\n";
	
	return 0;
}

