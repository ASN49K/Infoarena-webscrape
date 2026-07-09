#include<fstream>
#include<iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int tab[1025][1025], n, m, x[1025], y[1025], i, j;

void bordeaza_matrice()
{
	for(i = 0; i <= n; i++)
		tab[0][i] = 0;
	for(i = 0; i <= m; i++)
		tab[i][0] = 0;
}

void afis_solutie(int i, int j)
{
	if(i && j)
	{
		if(tab[i][j] == tab[i-1][j])
			afis_solutie(i-1, j);
		else
		{
			if(tab[i][j] == tab[i][j-1])
				afis_solutie(i, j-1);
			else
			{
				afis_solutie(i-1, j-1);
				fout << x[i] << " ";
			}
		}
	}
}

int max(int a, int b)
{
	return a > b ? a : b;
}

int main()
{
	fin >> n >> m;
	for(i = 1; i <= n; i++)
		fin >> x[i];
	for(i = 1; i <= m; i++)
		fin >> y[i];
	bordeaza_matrice();
	for(i = 1; i <= n; i++)
	{
		for(j = 1; j <=m; j++)
		{
			if(x[i] == y[j])
				tab[i][j] = 1 + tab[i-1][j-1];
			else
				tab[i][j] = max(tab[i-1][j], tab[i][j-1]);
		}
	}
	fout << tab[n][m] << endl;
	afis_solutie(n, m);
	return 0;
}

