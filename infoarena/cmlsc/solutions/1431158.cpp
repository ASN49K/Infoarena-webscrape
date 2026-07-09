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

	std::vector<int> result (n);

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			if (v[i-1] == u[j-1]) {

				c[i][j] = c[i-1][j-1] + 1;

			} else {
				c[i][j] = std::max (c[i][j-1], c[i-1][j]);
			}
		}
	}

	/*for (int i = 0; i < m + 1; ++i) {
		for (int j = 0; j < n + 1; ++j) {
			std::cout << c[i][j] << " ";
		}
		std::cout << "\n";
	}*/

	int k = 0;
	int i = n;
	int j = m;
	while (i > 0 && j > 0) {
		if (c[i][j] == c[i-1][j]) {
			--i;
		} else if (c[i][j] == c[i][j-1]) {
			--j;
		} else {
			result[k++] = v[i-1];
			--j; --i;
		}
	}

	std::ofstream g ("cmlsc.out");
	
	g << k << "\n";

	for (int i = 0; i < k; ++i) {
		g << result[i] << " ";
	}

	g << "\n";
	result.clear();
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