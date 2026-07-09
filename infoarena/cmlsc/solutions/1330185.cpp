#include <fstream>
#include <string.h>
#define NMax 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n, m, a[NMax], b[NMax], d[NMax][NMax], i, j, rec[NMax];
int getmax(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main()
{
	f >> n >> m;
	for (i = 1; i <= n; i++)
		f >> a[i];
	for (i = 1; i <= m; i++)
		f >> b[i];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i] == b[j])
				d[i][j] = d[i - 1][j - 1] + 1;
			else
				d[i][j] = getmax(d[i - 1][j], d[i][j - 1]);
		}
	}
	g << d[n][m] << "\n";
	i = n; 
	j = m;
	int len = d[n][m] + 1;
	while (len > 0) {
		if (a[i] == b[j]) {
			rec[--len] = a[i];
			i--;
			j--;
		}
		else {
			if (d[i - 1][j] > d[i][j - 1])
				i--;
			else
				j--;
		}
	}
	for (i = 1; i <= d[n][m]; i++)
		g << rec[i] << " ";
}
