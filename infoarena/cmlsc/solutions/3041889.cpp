#include <fstream>
#include <vector>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

void Read(int n, vector<int>& v) {
	v.resize(n);
	for (int i = 0; i < n; i++) {
		in >> v[i];
	}
}

void ComputeDp(const vector<int>& a, const vector<int>& b, 
		vector<vector<int>>& dp, vector<vector<pair<int, int>>>& prev) {
	dp.resize(a.size() + 1, vector<int>(b.size() + 1));
	prev.resize(a.size() + 1, vector<pair<int, int>>(b.size() + 1));

	for (int i = 1; i <= a.size(); i++) {
		for (int j = 1; j <= b.size(); j++) {
			int best = dp[i - 1][j];
			pair<int, int> bests_prev = {-1, 0};

			if (dp[i][j - 1] > best) {
				best = dp[i][j - 1];
				bests_prev = {0, -1};
			}

			if (a[i - 1] == b[j - 1] && dp[i - 1][j - 1] + 1 > best) {
				best = dp[i - 1][j - 1] + 1;
				bests_prev = {-1, -1};
			}

			dp[i][j] = best;
			prev[i][j] = bests_prev;
		}
	}
}

void Solve(vector<int>& a, vector<int>& b) {
	vector<vector<int>> dp;
	vector<vector<pair<int, int>>> prev;
	ComputeDp(a, b, dp, prev);
	
	out << dp[a.size()][b.size()] << "\n";
	
	vector<int> ans;
	for (int i = a.size(), j = b.size(); i > 0 && j > 0; ) {
		pair<int, int> p = prev[i][j];
		if (p == make_pair(-1, -1)) {
			ans.push_back(a[i - 1]);
		}
		i += p.first;
		j += p.second;
	}
	reverse(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		out << ans[i] << " ";
	}
	out << "\n";
}

int main() {
	int n, m; in >> n >> m;

	vector<int> a; Read(n, a);
	vector<int> b; Read(m, b);

	Solve(a, b);
	return 0;
}