#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int NMAX = 1024;
char dp[NMAX][NMAX];

int main() {
	freopen("cmlsc.in", "r", stdin);
	freopen("cmlsc.out", "w", stdout);
	int n, m, x;
	vector<int> first;
	vector<int> second;
	cin >> n >> m;
	first.push_back(0);
	for (int i = 0; i < n; ++ i) {
		cin >> x;
		first.push_back(x);
	}

	second.push_back(0);
	for (int i = 0; i < m; ++ i) {
		cin >> x;
		second.push_back(x);
	}

	for (int i = 1; i <= n; ++ i) {
		for (int j = 1; j <= m; ++ j) {
			if (first[i] == second[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}
	int i, j;
	i = n;
	j = m;
	vector<int> solution;
	
	while (i && j) {
		if (first[i] == second[j]) {
			solution.push_back(first[i]);
			i --;
			j --;
		} else if (dp[i][j - 1] > dp[i - 1][j]) {
			j --;
		} else {
			i --;
		}
	}

	cout << solution.size() << "\n";
	for (int i = solution.size() - 1; i >= 0; -- i) {
	 	cout << solution[i] << " ";
	}
	cout << "\n";
	return 0;
}