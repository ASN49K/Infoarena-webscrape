#include <fstream>
#include <vector>
#include <assert.h>
#include <iostream>

std::vector<int> cmlsc(std::vector<int> a, std::vector<int> b, int m, int n) {
	std::vector<int> solution;
	std::vector<std::vector<int>> c(m * n, std::vector<int>(m * n));

	for (int i = 1 ; i <= m ; ++i) {
		for (int j = 1 ; j <= n ; ++j) {
			if (a[i] == b[j]) {
				c[i][j] = c[i-1][j-1] + 1;
			} else {
				c[i][j] = std::max(c[i-1][j], c[i][j-1]);
			}
		}
	}

	int i, j;
	for (i = m, j = n ; i;) {
		if (a[i] == b[j]) {
			solution.push_back(a[i]);
			--i;
			--j;
		} else if (c[i-1][j] < c[i][j-1]){
			--j;
		} else {
			--i;
		}
	}

	return solution;
}

int main() {
	std::ifstream in("cmlsc.in");
	std::ofstream out("cmlsc.out");

	int m, n, x;
	in >> m >> n;
	assert(1 <= m && m <= 1024 && 1 <= n && n <= 1024);
	std::vector<int> solution;
	std::vector<int> a(m + 1), b(n + 1);

	for (int i = 1 ; i <= m ; ++i) {
		in >> a[i];
	}

	for (int i = 1 ; i <= n ; ++i) {
		in >> b[i];
	}

	solution = cmlsc(a, b, m, n);
	out << solution.size() << '\n';
	for (auto it = solution.begin() ; it != solution.end() ; ++it) {
		out << *it << " ";
	}

	out << '\n';
	return 0;
}