#include <iostream>
#include <fstream>
#include <stack>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <map>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M;
int v1[1500];
int v2[1500];
int stored[1500][1500];

int rez[1025 * 1030], ind;

int LCS(int n, int m) {
	if (stored[n][m])
		return stored[n][m];

	int result;

	if (n == 0 || m == 0)
		result = 1;

	else if (v1[n] == v2[m]) {
		result = (1 + LCS(n - 1, m - 1));
	}

	else {
		int tip1 = LCS(n, m - 1);
		int tip2 = LCS(n - 1, m);

		result = max(tip1, tip2);
	}
	stored[n][m] = result;
	return result;
}

int main() {
	fin >> N >> M;

	for (int i = 1; i <= N; ++i)
		fin >> v1[i];

	for (int i = 1; i <= M; ++i)
		fin >> v2[i];

	fout << LCS(N, M) - 1 << "\n";

	for (int i = N, j = M; i; )
		if (v1[i] == v2[j]) {
			rez[ind++] = v1[i];
			i--;
			j--;
		}
		else if (stored[i - 1][j] < stored[i][j - 1])
			j--;
		else
			i--;

	for (int i = ind - 1; i >= 0; --i)
		fout << rez[i] << " ";

	return 0;
}

