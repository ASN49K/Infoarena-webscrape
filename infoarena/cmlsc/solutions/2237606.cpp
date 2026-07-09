#include <fstream>
#include <vector>
#include <algorithm>  
using namespace std;
#define IntArray vector<int>
#define IntMatrix vector<vector<int>>

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

IntArray longestCommonSubsequence(IntArray, IntArray);

int main() {
	int n, m;
	fin >> n >> m;
	IntArray a(n), b(m);
	for (int i = 0; i < n; ++i) {
		fin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
		fin >> b[i];
	}
	IntArray lcs = longestCommonSubsequence(a, b);
	fout << lcs.size() << "\n";
	for_each(lcs.begin(), lcs.end(), [](int it) { fout << it << " "; });
	return 0;
}

IntArray longestCommonSubsequence(IntArray a, IntArray b) {
	int n = a.size();
	int m = b.size();
	IntMatrix dp = IntMatrix(n + 1, IntArray(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = (a[i - 1] == b[j - 1]) ? dp[i - 1][j - 1] + 1 : max(dp[i - 1][j], dp[i][j - 1]);
		}
	}

	IntArray lcs;

	while (n > 0 && m > 0) {
		if (a[n - 1] == b[m - 1]) {
			lcs.push_back(a[n - 1]);
			--n;
			--m;
		}
		else {
			if (dp[n - 1][m] > dp[n][m - 1]) {
				--n;
			}
			else {
				--m;
			}
		}
	}
	reverse(lcs.begin(), lcs.end());
	return lcs;
}

