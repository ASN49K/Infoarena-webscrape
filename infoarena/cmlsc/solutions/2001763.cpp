#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int A[1025], B[1025], m, n, dp[1025][1025], rez[1025], nRez;

int max(int x, int y) {
	return ((x > y) ? x : y);
}

int main() {
	
	fin >> m >> n;
	for (int i = 1; i <= m; i++)
		cin >> A[i];
	for (int i = 1; i <= n; i++)
		cin >> B[i];

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (A[i] == B[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	nRez = dp[m][n];
	for (int i = m, j = n; dp[i][j]; ) {
		if (A[i] == B[j]) {
			rez[dp[i][j]] = A[i];
			i--;
			j--;
		}
		else if (dp[i - 1][j] >= dp[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}

	for (int i = 1; i <= nRez; fout << rez[i++]);
	return 0;
}