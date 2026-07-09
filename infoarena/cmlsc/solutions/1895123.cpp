#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

template<typename T>
std::vector<T> lcs(std::vector<T> a, std::vector<T> b) {

	std::vector<std::vector<int>> c(a.size()+1, std::vector<int>(b.size()+1,0));

	for (size_t i = 1; i <= a.size(); i++) {

		for (size_t j = 1; j <= b.size(); j++) {
			if (a[i-1] == b[j-1])
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = std::max(c[i-1][j], c[i][j-1]);
		}
	}

	std::vector<T> solution;

	int i = a.size(), j = b.size();

	while (i && j) {

		if (a[i - 1] == b[j - 1]) {
			solution.push_back(a[i-1]);
			j--;
			i--;
		}

		else if (c[i - 1][j] > c[i][j - 1])
			i--;
		else j--;
	}

	return solution;
}

int main(void) {

	std::ifstream in("cmlsc.in");
	int m, n;
	in >> m >> n;

	std::vector<int> a(m),b(n);

	for (int i = 0; i < m; i++)
		in >> a[i];

	for (int i = 0; i < n; i++)
		in >> b[i];

	in.close();

	std::ofstream out("cmlsc.out");

	std::vector<int> res = lcs(a, b);

	out << res.size()<<"\n";

	for (auto iter = res.rbegin(); iter != res.rend(); iter++)
		out << *iter<<" ";

	out.close();

	return 0;
}


