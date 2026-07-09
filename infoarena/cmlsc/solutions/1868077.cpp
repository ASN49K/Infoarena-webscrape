#include <iostream>
#include <fstream>

using namespace std;
int n, m, k;
int a[2000], b[2000];
int L[2000][2000];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int lcs() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				L[i][j] = L[i - 1][j - 1] + 1;
			}
			else
			{
				int s1 = L[i - 1][j];
				int s2 = L[i][j - 1];
				if (s1 > s2)
					L[i][j] = s1;
				else L[i][j] = s2;
			}
		}
	}
	return L[n][m];
}

void findlcs() {
	int maxim = 0;
	for (int j = 1; j <= m; j++) {
		for (int i = 1; i <= n; i++) {
			if (maxim < L[i][j]) {
				maxim = L[i][j];
				out << a[i] << " ";
			}
		}
	}
}

int main() {
	in >> n >> m;

	for (int i = 1; i <= n; i++)
		in >> a[i];

	for (int i = 1; i <= m; i++)
		in >> b[i];

	out << lcs() << "\n";

	findlcs();
}