# include <fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

int n, m, a[1050], b[1050], i, j, mat[1050][1050], sir[1050];
int main ()
{
	f >> n >> m;
	for (i = 1; i <= n; ++i)
		f >> a[i];
	for (j = 1; j <= m; ++j)
		f >> b[j];
	
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			if (a[i] == b[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = max (mat[i - 1][j], mat[i][j - 1]);
	
	g << mat[n][m] << '\n';
	
	for (i = n, j = m; i >= 1; )
		if (a[i] == b[j])
			sir[++sir[0]] = a[i], --i, --j;
		else
			if (mat[i - 1][j] < mat[i][j - 1])
				--j;
			else 
				--i;
	
	for (i = sir[0]; i >= 1; --i)
		g << sir[i] << ' ';
	
	g.close ();
	return 0;
}