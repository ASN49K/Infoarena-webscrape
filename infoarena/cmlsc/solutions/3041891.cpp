#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int kNMax = 1024;

int a[kNMax + 1];
int b[kNMax + 1];

int dp[kNMax + 1][kNMax + 1];
int prev_i[kNMax + 1][kNMax + 1];
int prev_j[kNMax + 1][kNMax + 1];

int main() {
	// citire
	int n, m; in >> n >> m;
	for (int i = 1; i <= n; i++) {
		in >> a[i];
	}
	for (int i = 1; i <= m; i++) {
		in >> b[i];
	}

	// calculat dp
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int best = dp[i - 1][j];
			int pi = -1, pj = 0;

			if (dp[i][j - 1] > best) {
				best = dp[i][j - 1];
				pi = 0; pj = -1;
			}

			if (a[i] == b[j] && dp[i - 1][j - 1] + 1 > best) {
				best = dp[i - 1][j - 1] + 1;
				pi = -1; pj = -1;
			}

			dp[i][j] = best;
			prev_i[i][j] = pi;
			prev_j[i][j] = pj;
		}
	}

	// afisarea raspunsului
	out << dp[n][m] << "\n";
	
	vector<int> ans;
	for (int i = n, j = m; i > 0 && j > 0; ) {
		int pi = prev_i[i][j];
		int pj = prev_j[i][j];

		if (pi == -1 && pj == -1) {
			ans.push_back(a[i]);
		}

		i += pi;
		j += pj;
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		out << ans[i] << " ";
	}
	out << "\n";

	return 0;
}