#include <iostream>
#include <fstream>
#include <vector>
#define nmax 1030
using namespace std;

bool seen[nmax][nmax];
int n, m, dp[nmax][nmax], a[nmax], b[nmax];
vector <int> sol;

int solve(int i, int j) {
	if(seen[i][j] || i == 0 || j == 0) return dp[i][j];
	seen[i][j] = true;

	if(a[i] == b[j]) dp[i][j] = 1 + solve(i-1, j-1);
	else dp[i][j] = max(solve(i-1, j), solve(i, j-1));

	return dp[i][j];
}

void reconstruct(int i, int j) {
	if(i == 0 || j == 0) return;
	if(a[i] == b[j]) {
		sol.push_back(a[i]);
		reconstruct(i-1, j-1);
	}
	else {
		if(solve(i-1, j) > solve(i, j-1)) reconstruct(i-1, j);
		else reconstruct(i, j-1);
	}
}

int main() {
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	f>>n>>m;
	for(int i=1; i<=n; i++) f>>a[i];
	for(int i=1; i<=m; i++) f>>b[i];

	g<<solve(n, m)<<"\n";
	reconstruct(n, m);

	for(int i=int(sol.size())-1; i>=0; i--) g<<sol[i]<<" "; g<<"\n";

	return 0;
}
