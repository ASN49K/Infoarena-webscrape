#include<fstream>
using namespace std;
int main()
{
	fstream f("cmlsc.in", ios::in);
	fstream g("cmlsc.out", ios::out);
	int c[1024][1024], a[1024], b[1024], i, n, m, j, s[1024], k;
	f >> n >> m;
	for (i = 1; i <= n; i++)
	{
		f >> a[i];
		c[i][0] = 0;
	}
	for (j = 1; j <= m; j++)
	{
		f >> b[j];
		c[0][j] = 0;
	}
	for (i = 1; i <= n;i++)
	for (j = 1; j <= m;j++)
	if (a[i] == b[j])c[i][j] = c[i - 1][j - 1] + 1;
	else if (c[i - 1][j] > c[i][j - 1])c[i][j] = c[i - 1][j];
	else c[i][j] = c[i][j - 1];
	g << c[n][m] << endl;
	i = n; 
	j = m;
	k = 0;
	while (c[i][j] != 0)
	{
		if (a[i] == b[j])
		{
			s[k++] = a[i];
			i--;
			j--;
		}
		else if (c[i][j - 1] < c[i - 1][j])i--;
		else j--;
	}
	for (i = k-1; i >= 0; i--)
		g << s[i] << " ";

	return 0;
}

