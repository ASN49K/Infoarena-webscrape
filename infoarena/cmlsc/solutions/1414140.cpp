#include <fstream>

#define NMax 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, v1[NMax], v2[NMax], d[2][NMax], rec[NMax], k;

int getmax(int a, int b)
{
	if (a > b)
		return a;
	return b;
}

int main()
{
	f >> m >> n;

	for (int i = 1; i <= m; i++)
		f >> v1[i];

	for (int i = 1; i <= n; i++)
		f >> v2[i];

	int ind = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (v1[i] == v2[j])
				d[ind][j] = d[1 - ind][j - 1] + 1;
			else
				d[ind][j] = getmax(d[1 - ind][j], d[ind][j - 1]);
		}
		ind = 1 - ind;
	}

	g << d[1 - ind][n] << "\n";

	int i = m, j = n;
	ind = 1 - ind;

	while (i != 0 && j != 0) {
		if (v1[i] == v2[j]) {
			rec[++k] = v1[i];
			i--;
			j--;
		}
		else {
			if (d[1 - ind][j] > d[ind][j - 1])
				i--;
			else
				j--;
		}
	}

	for (int i = k; i >= 1; i--)
		g << rec[i] << " ";
}