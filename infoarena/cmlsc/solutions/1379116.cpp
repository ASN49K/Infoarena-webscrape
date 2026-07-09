#include <fstream>
#define NMax 1035
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[NMax], b[NMax], d[NMax][NMax], rec[NMax];

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
		f >> a[i];
	for (int i = 1; i <= n; i++)
		f >> b[i];
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j])
				d[i][j] = d[i - 1][j - 1] + 1;
			else 
				d[i][j] = getmax(d[i-1][j], d[i][j-1]);
		}
	}
	g << d[m][n] << "\n";
	int f = m;
	int s = n;
	int ind = d[m][n];
	while (ind > 0) {
		if (a[f] == b[s]) {
			rec[ind--] = a[f];
			f--;
			s--;
		}
		else {
			if (d[f][s - 1] > d[f - 1][s])
				s--;
			else
				f--;
		}
	}
	for (int i = 1; i <= d[m][n]; i++)
		g << rec[i] << " ";
}