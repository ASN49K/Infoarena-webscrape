#include <fstream>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

void ShowElements (int **values, int *a, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (values[i][j] == -1)
	{
		ShowElements(values, a, i-1, j-1);
		fout << a[i] << " ";
	}
	else if (values[i][j] == -2)
		ShowElements(values, a, i-1, j);
	else
		ShowElements(values, a, i, j-1);
}

void CelMaiLungSubsirComun ()
{
	int m, n, i, j, max, subsirDimensiune = 0;
	int *a, *b;
	
	fin >> m >> n;
	a = new int[m+1];
	b = new int[n+1];
	a[0] = b[0] = 0;
	for (i = 1; i <= m; i++)
		fin >> a[i];
	for (i = 1; i <= n; i++)
		fin >> b[i];

	// create the matrix
	int **c, **values;
	c = new int*[m+1];
	values = new int*[m+1];
	for (i = 0; i <= m; i++)
	{
		c[i] = new int[n+1];
		values[i] = new int[n+1];
	}
	for (i = 0; i <= n; i++)
		c[0][i] = values[0][i] = 0;
	for(i = 0; i <= m; i++)
		c[i][0] = values[i][0] = 0;

	// calculate the values
	for (i = 1; i <= m; i++)
		for (j = 1; j <= n; j++)
		{
			if (a[i] == b[j])
			{
				c[i][j] = c[i-1][j-1] + 1;
				// pentru diagonala
				values[i][j] = -1;
			}
			else if ( c[i-1][j] > c[i][j-1] )
			{
				c[i][j] = c[i-1][j];
				// pentru linia de sus, aceasi coloana
				values[i][j] = -2;
			}
			else
			{
				c[i][j] = c[i][j-1];
				// pentru aceasi linie, coloana din stanga
				values[i][j] = -3;
			}
		}

	// compute the results
	fout << c[m][n] <<"\n";
	ShowElements(values, a, m, n);

	fin.close();
	fout.close();
}

int main ()
{
	CelMaiLungSubsirComun();
	return 0;
}