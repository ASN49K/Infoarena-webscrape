#include<bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.txt");
ofstream fout("cmlsc.out");
int a[1024], b[1024], D[1024][1024], n, m, sir[1024];
int main()
{
	int i, j;
	fin >> m >> n;
	for (i = 1; i <= m; i++) fin >> a[i];
	for (i = 1; i <= n; i++) fin >> b[i];
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
			if (a[i] == b[j]) D[i][j] = 1 + D[i - 1][j - 1];
			else D[i][j] = max(D[i - 1][j], D[i][j - 1]);
	i = m; j = n;
	int nr = 0;
	while (i)
	{
		if (a[i] == b[j])
		{
			sir[++nr] = a[i];
			i--;
			j--;
		}
		else if (D[i - 1][j] < D[i][j - 1])
			j--;
		else i--;
	}
	fout << nr<<"\n";
	for (i = nr; i >= 1; i--) fout << sir[i] << " ";
	return 0;
}
