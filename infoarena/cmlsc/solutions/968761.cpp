#include <fstream>

void CelMaiLungSubsirComun ()
{
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");
	int m, n, i, j, max, subsirDimensiune = 0;
	int *a, *b, *subsir;
	
	fin >> m >> n;
	a = new int[m+1];
	b = new int[n+1];
	max = ( (m+1) > (n+1) ) ? (m+1) : (n+1);
	subsir = new int[max];
	a[0] = b[0] = 0;
	for (i = 1; i <= m; i++)
		fin >> a[i];
	for (i = 1; i <= n; i++)
		fin >> b[i];

	// create the matrix
	int **c;
	c = new int*[m+1];
	for (i = 0; i <= m; i++)
		c[i] = new int[n+1];
	for (i = 0; i <= n; i++)
		c[0][i] = 0;
	for(i = 0; i <= m; i++)
		c[i][0] = 0;

	// calculate the values
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (a[i] == b[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
				subsir[subsirDimensiune++] = a[i];
			}
			else if ( c[i-1][j] > c[i][j-1] )
				c[i][j] = c[i-1][j];
			else
				c[i][j] = c[i][j-1];
		}

	// compute the results
	fout << c[m][n] <<"\n";
	for (i = 0; i < c[m][n]; i++)
		fout << subsir[i] << " ";

	fin.close();
	fout.close();
}

int main ()
{
	CelMaiLungSubsirComun();
	return 0;
}