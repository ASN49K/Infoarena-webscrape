#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int N = 1025;

int a[N], b[N];
int best[N][N];
int n, m;

void read() {
	in >> n >> m;

	for (int i = 0; i < n; ++i)
		in >> a[i];
	for (int i = 0; i < m; ++i)
		in >> b[i];
}

int solve() {
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			best[i][j] = max(best[i-1][j], best[i][j-1]);

			if (a[i] == b[j])
				best[i][j] = max(curMax, best[i-1][j-1] + 1);
		}

	return best[n][m];
}

int main() {
	read();
	out << solve() << "\n";

	return 0;
}
