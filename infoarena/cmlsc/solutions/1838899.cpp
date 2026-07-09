#include <stdio.h>
#include <vector>
using namespace std;

const int NMAX = 1024;
char dp[NMAX][NMAX];

int main() {
	FILE *in, *out;
	in = fopen("cmlsc.in", "rt");
	out = fopen("cmlsc.out", "wt");
	int n, m;
	vector<int> first;
	vector<int> second;
	fscanf(in, "%d%d", &n, &m);
	for (int i = 0; i < n; ++ i) {
		int x;
		fscanf(in, "%d", &x);
		first.push_back(x);
	}

	for (int i = 0; i < m; ++ i) {
		int x;
		fscanf(in, "%d", &x);
		second.push_back(x);
	}

	for (int i = 0; i < n; ++ i) {
		for (int j = 0; j < m; ++ j) {
			if (i && j) {
				if (first[i] == second[j])
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
				else 
					dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			} else if (i && !j) {
				if (first[i] == second[j])
					dp[i][j] = dp[i - 1][j] + 1;
				else 
					dp[i][j] = dp[i - 1][j];
			} else if (j && !i) {
				if (first[i] == second[j])
					dp[i][j] = dp[i][j - 1] + 1;
				else 
					dp[i][j] = dp[i][j - 1];
			}
		}
	}

	fprintf(out, "%d\n", dp[n - 1][m - 1]);
	int i, j;
	i = n - 1;
	j = m - 1;
	vector<int> solution;
	
	while (i && j) {
		if (dp[i][j] > dp[i - 1][j]) {
			solution.push_back(first[i]);
			i --;
		} else if (dp[i][j] > dp[i][j - 1]) {
			solution.push_back(second[j]);
			j --;
		} else {
			i --;
		}
	}

	for (int i = solution.size() - 1; i >= 0; -- i) {
		fprintf(out, "%d ", solution[i]);
	}
	fclose(in);
	fclose(out);
}