#include <fstream>
#include <stack>

#define nmax 1025

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[nmax], b[nmax], mat[nmax][nmax];
stack <int> S;

int maxim(int a, int b)
{
	if (a >= b)
		return a;
	return b;
}

int main()
{
	f >> m >> n;
	for (int i = 1; i <= m; ++i)
		f >> a[i];
	for (int i = 1; i <= n; ++i)
		f >> b[i];
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i] == b[j])
				mat[i][j] = 1 + mat[i - 1][j - 1];
			else
				mat[i][j] = maxim(mat[i - 1][j], mat[i][j - 1]);
	g << mat[m][n] << "\n";
	int i = m, j = n, v = mat[m][n];
	while (mat[i][j] != 0)
	{
		if (mat[i][j] == v)
			if (mat[i - 1][j] == v)
				--i;
			else
				if (mat[i][j - 1] == v)
					--j;
				else
				{
					S.push(a[i]);
					--v;
					--i;
					--j;
				}
	}
	while (!S.empty())
	{
		g << S.top() << " ";
		S.pop();
	}
}