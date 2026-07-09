#include <iostream>
#include <vector>
#include <stack>
#include <fstream>

#define NMAX 1024

int matrix[NMAX][NMAX];


int main() {
	int n, m, x, count = 0;
	int v[NMAX] = {0}, w[NMAX] = {0}, sir[NMAX] = {0};
	std::ifstream in;
	std::ofstream out;

	in.open ("cmlsc.in");
	out.open ("cmlsc.out");

	in >> m;
	in >> n;

	for (int i = 1; i <= m; ++i) {
		in >> v[i];
	}

	for (int i = 1; i <= n; ++i) {
		in >> w[i];
	}

	for (int i = 1; i <= m; ++i) {
		for (int j = 1; j <=n; ++j) {
			if (v[i] == w[j])
                matrix[i][j] = 1 + matrix[i-1][j-1];
            else	
                matrix[i][j] = std::max (matrix[i-1][j], matrix[i][j-1]);
		}
	}

	for (int i = m, j = n; i > 0; ) {
		if (v[i] == w[j])
            sir[++count] = v[i], --i, --j;
        else if (matrix[i-1][j] < matrix[i][j-1])
            --j;
        else
            --i;
	}
	out << count << "\n";
	for (int i = count; i > 0; --i) {
		out << sir[i];
		out << " ";	
	}

	return 0;
}