#include <fstream>
#define max(a, b) (a > b) ? a : b 

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int lcs[1030][1030], n, m, a[1030], b[1030], v[1030];

int main()
{
	int i, j, k = 1;

	fin >> n >> m;

	for (i = 1; i <= n; i++)
		fin >> a[i];

	for (j = 1; j <= m; j++)
		fin >> b[j];

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (a[i] == b[j])
				lcs[i][j] = 1 + lcs[i - 1][j - 1];
			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);

	fout << lcs[n][m] << '\n';

	while (i && j)
	{
		if (a[i] == b[j])
		{
			v[k++] = a[i];
			i--; j--;
		}
		else
			if (lcs[i - 1][j] > lcs[i][j - 1])
				i--;
			else
				j--;
	}

	for (k--; k >= 2; k--)
		fout << v[k] << ' ';

	fout << '\n';

	fin.close();
	fout.close();
	return 0;
}