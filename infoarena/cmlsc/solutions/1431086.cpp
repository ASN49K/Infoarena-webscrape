#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>

void maxSubsequence (std::vector<int> &v, std::vector<int> &u, int m, int n) {

	int **c = (int**) malloc ((m+1) * sizeof(int*));

	for (int i = 0; i <= m; ++i) {
		c[i] = (int*) calloc (n + 1, sizeof(int));
	}

	for (int i = 0; i < m + 1; ++i) {
		c[i][0] = 0;
	}

	for (int j = 0; j < n + 1; ++j) {
		c[0][j] = 0;
	}

	std::vector<int> result;

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (v[i-1] == u[j-1]) {

				c[i][j] = c[i-1][j-1] + 1;
				result.push_back (v[i-1]);
			} else {
				c[i][j] = std::max (c[i][j-1], c[i-1][j]);
			}
		}
	}

	for (int i = 0; i < m + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			std::cout << c[i][j] << " ";
		}
		std::cout << "\n";
	}

	std::ofstream g ("cmlsc.out");
	g << result.size() << "\n";

	for (unsigned int i = 0; i < result.size(); ++i) {
		g << result[i] << " ";
	}
	g << "\n";
	g.close();
}

int main (void) {
	std::ifstream f ("cmlsc.in");

	int m, n;
	f >> m >> n;

	std::vector <int> v (m);
	std::vector <int> u (n);

	for (int i = 0; i < m; ++i) {
		f >> v[i];
	}

	for (int i = 0; i < n; ++i) {
		f >> u[i];
	}

	maxSubsequence (v, u, m, n);

	v.clear();
	u.clear();
	f.close();
	return 0;
}