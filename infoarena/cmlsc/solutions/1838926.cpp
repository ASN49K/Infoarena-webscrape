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
	for (int i = 0; i < n; ++ i) {
		cin >> x;
		first.push_back(x);
	}

	for (int i = 0; i < m; ++ i) {
		cin >> x;
		second.push_back(x);
	}

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			if (i && j) {
				if (first[i] == second[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				else 
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			} else if (i && !j) {
				if (first[i] == second[j])
					dp[i][j] = 1;
				else 
					dp[i][j] = dp[i - 1][j];
			} else if (j && !i) {
				if (first[i] == second[j])
					dp[i][j] = 1;
				else 
					dp[i][j] = dp[i][j - 1];
			}
		}
	}
	int i, j;
	i = n - 1;
	j = m - 1;
	vector<int> solution;
	
	while (i || j) {
		if (i && dp[i][j] > dp[i - 1][j]) {
			solution.push_back(first[i]);
			i --;
		} else if (j && dp[i][j] > dp[i][j - 1]) {
			solution.push_back(second[j]);
			j --;
		} else if (i) {
			i --;
		} else {
			j --;
		}
	}

	cout << solution.size() << "\n";
	for (int i = solution.size() - 1; i >= 0; -- i) {
	 	cout << solution[i] << " ";
	}
	cout << "\n";
	return 0;
}