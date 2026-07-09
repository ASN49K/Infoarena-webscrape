#include <fstream>
#include <vector>
#include <stack>

#include <iostream>

using namespace std;

int main() {
	int M, N;
	vector<int> A, B;
	stack<int> cmlsc;
	int MAX;
	int i, j;
	vector<vector<int>> c;
	vector<vector<char>> s;

	// input
	ifstream f("cmlsc.in");
	f >> M >> N;
	A.resize(M + 1);
	for (i = 1; i <= M; ++i) {
		f >> A[i];
	}
	B.resize(N + 1);
	for (j = 1; j <= N; ++j) {
		f >> B[j];
	}
	f.close();

	// solve
	c.resize(M + 1);
	s.resize(M + 1);
	for (i = 0; i <= M; ++i) {
		c[i].resize(N + 1);
		s[i].resize(N + 1);
		c[i][0] = 0;
	}
	for (j = 0; j <= N; ++j) {
		c[0][j] = 0;
	}

	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= N; ++j) {
			if (A[i] == B[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				s[i][j] = 'x';
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				s[i][j] = '|';
			}
			else {
				c[i][j] = c[i][j - 1];
				s[i][j] = '-';
			}
		}
	}

	// output
	ofstream g("cmlsc.out");
	MAX = c[M][N];
	g << MAX << '\n';
	i = M; j = N;
	while (MAX > 0 && i > 0 && j > 0) {
		if (s[i][j] == 'x') {
			cmlsc.push(A[i]);
			--i; --j; --MAX;
		}
		else if (s[i][j] == '|') {
			--i;
		}
		else {
			--j;
		}
	}
	while (!cmlsc.empty()) {
		g << cmlsc.top() << ' ';
		cmlsc.pop();
	}
	g << '\n';
	g.close();

	return 0;
}
