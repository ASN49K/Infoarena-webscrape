#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

const int NMAX = 1024;
const int MMAX = 1024;

int n, m;
int  a[NMAX + 1];
int  b[MMAX + 1];
int dp[NMAX + 1][MMAX + 1];

void citeste() {
	f >> n >> m;
	for (int i = 1; i <= n; i++) f >> a[i];
	for (int i = 1; i <= m; i++) f >> b[i];
}

void rezolva() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i] != b[j])
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			else
				dp[i][j] = 1 + dp[i - 1][j - 1];
}

vector <int> reconstruieste(int i, int j) {
	if (i == 0 || j == 0) {
		return vector <int> ();
	}

	if (a[i] == b[j]) {
		vector <int> path = reconstruieste(i - 1, j - 1);
		path.push_back(a[i]);
		return path;
	}

	if (dp[i][j] == dp[i - 1][j])
		return reconstruieste(i - 1, j);
	return reconstruieste(i, j - 1);
}

void scrie() {
	g << dp[n][m] << '\n';
	vector <int> path = reconstruieste(n, m);
	int l = path.size();
	for (int i = 0; i < l; i++) 
		g << path[i] << ' ';
	g << '\n';
}

int main() {
	citeste();
	rezolva();
	scrie();
	return 0;
}
