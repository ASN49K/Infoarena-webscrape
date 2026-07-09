#include <fstream>
using namespace std;

const int NMAX = 1025;
int a[NMAX], b[NMAX];
int d[NMAX][NMAX];
int r[NMAX], contor = 0;

int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}

int main() {
	int n, m;
	ifstream in("cmlsc.in");
	in >> n >> m;
	for (int i = 1; i <= n; i++)
		in >> a[i];
	for (int i = 1; i <= m; i++)
		in >> b[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				d[i][j] = 1 + d[i - 1][j - 1];
				r[contor++] = a[i];
			}
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	in.close();
	ofstream out("cmlsc.out");
	out << d[n][m] << '\n';
	for (int i = 0; i < contor; i++)
		out << r[i] << ' ';
	out.close();
	return 0;
}