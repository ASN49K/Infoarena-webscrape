#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findSubsequence(
    const vector<int>& a,
    const vector<int>& b,
    const vector<vector<int>>& dp) {
	vector<int> sequence;
	for (int i = int(a.size()), j = int(b.size()); i > 0 && j > 0; ) {
		if (a[i - 1] == b[j - 1] && dp[i][j] == 1 + dp[i - 1][j - 1]) {
			sequence.push_back(a[i]);
			--i;
			--j;
		} else if (dp[i][j] == dp[i - 1][j]) {
			--i;
		} else if (dp[i][j] == dp[i][j - 1]) {
			--j;
		}
	}
	reverse(sequence.begin(), sequence.end());
	return sequence;
}

vector<int> longestCommonSubsequence(
    const vector<int>& a,
    const vector<int>& b) {
	const int n = int(a.size());
	const int m = int(b.size());
	auto dp = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			dp[i][j] = max(
          max(dp[i - 1][j], dp[i][j - 1]),
          dp[i - 1][j - 1] + (a[i - 1] == b[j - 1] ? 1 : 0));
		}
	}
  return findSubsequence(a, b, dp);
}

int main() {
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");
	int n[2];
	in >> n[0] >> n[1];
	vector<int> sequences[2];
	for (int i = 0; i < 2; ++i) {
		sequences[i] = vector<int>(n[i]);
		for (int j = 0; j < n[i]; ++j) {
			in >> sequences[i][j];
		}
	}
	const auto subsequence = longestCommonSubsequence(sequences[0], sequences[1]);
	out << int(subsequence.size()) << "\n";
	for (int i = 0; i < int(subsequence.size()); ++i) {
		out << subsequence[i] << (i + 1 < int(subsequence.size()) ? " " : "\n");
	}
	in.close();
	out.close();
	return 0;
}
