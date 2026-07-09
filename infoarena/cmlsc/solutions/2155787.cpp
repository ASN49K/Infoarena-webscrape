#include <fstream>
#define NMax 1024
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[NMax], b[NMax], c[NMax][NMax], sir[NMax], bst;
int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
int main(void)
{
	int i, j;
	f >> n >> m;
	for (i = 1; i <= n; i++)
		f >> a[i];
	for (i = 1; i <= m; i++)
		f >> b[i];

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
		if (a[i] == b[j])
			c[i][j] = 1 + c[i - 1][j - 1];
		else
			c[i][j] = max(c[i - 1][j], c[i][j - 1]);
	for (i = n, j = m; i; )
		if (a[i] == b[j])
			sir[++bst] = a[i], i--, j--;
		else if (c[i - 1][j] < c[i][j - 1])
			j--;
		else
			i--;

	g << bst << "\n";
	for (i = bst; i; i--)
		g << sir[i] << " ";
	return 0;
}