#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define NMAX 1025

using namespace std;

int a[NMAX], b[NMAX], n, m;
int c[NMAX][NMAX];
vector<int> sol;

void read() {

	ifstream in("cmlsc.in");

	in >> n >> m;

	for (int i = 1; i <= n; i++)
		in >> a[i];

	for (int i = 1; i <= m; i++)
		in >> b[i];

	in.close();
}

int main() {

	read();

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {

			if (a[i] == b[j])
				c[i][j] = c[i - 1][j - 1] + 1;
			else
				c[i][j] = max(c[i][j - 1], c[i - 1][j]);
		}
	int i = n, j = m;

	while (i > 0) {

		if (a[i] == b[j]) {

			sol.push_back(a[i]);
			i--;
			j--;
		}
		else {

			if (c[i][j - 1] > c[i - 1][j])
				j--;
			else
				i--;
		}
	}

	ofstream out("cmlsc.out");
	out << sol.size() << "\n";
	for (auto it = sol.rbegin(); it != sol.rend(); it++)
		out << *it << " ";
	out.close();
	return 0;
}