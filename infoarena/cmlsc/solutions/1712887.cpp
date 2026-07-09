#include <fstream>
#include <algorithm>
#include <string.h>
using namespace std;

ifstream f{ "cmlsc.in" };
ofstream q{ "cmlsc.out" };

int n, m, a[1050], b[1050], best[1050][1050], seq[1050];

int main() {

	int k = 0;

	f >> n >> m;

	for (int i = 1; i <= n; i++) f >> a[i];
	for (int j = 1; j <= m; j++) f >> b[j];

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) best[i][j] = best[i - 1][j - 1] + 1;
			else best[i][j] = max(best[i][j - 1], best[i - 1][j]);
		}
	}
	q << best[n][m] << "\n";
	for (int i = n, j = m; i > 0 && j > 0 ;) {
		if (a[i] == b[j]) seq[++k] = a[i], i--, j--;
		else if (best[i][j-1] <  best[i - 1][j]) i--;
		else j--;
	}
	for (; k > 0; k--)q << seq[k] << " ";


	f.close();
	q.close();
	return 0;
}