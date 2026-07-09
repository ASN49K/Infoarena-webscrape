#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <algorithm>
#define nmax 1<<9+1
using namespace std;

int n, m;
short dp[nmax][nmax];
short a[nmax], b[nmax];
stack <int> lcs;

void back(int i, int j) {
	if(i==0 || j==0) return;
	
	if(a[i] == b[j]) {
		lcs.push(a[i]);
		back(i-1, j-1);
		return;
	}

	if(dp[i-1][j] > dp[i][j-1]) back(i-1, j);
	else back(i, j-1);
	
}


int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	int i, j;

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

	back(n, m);
	while(!lcs.empty()) {
		g<<lcs.top()<<" ";
		lcs.pop();
	}

  	return 0;
}
