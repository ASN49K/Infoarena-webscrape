/*
 * Autor: Paul Herman
 * Problema: cel mai lung subsir comun
 * Data: 17.01.2012
 * Punctaj: -
 * Link: http://www.infoarena.ro/problema/cmlsc
 */
#include <fstream>
#include <vector>
using namespace std;

int n, m; //Lungimile celor doua secvente
int a[1025], b[1025]; //Cele doua secvente
int d[1025][1025]; //Matricea pt. dinamica
vector<int> subsir; //Subsirul comun

inline void cmlsc()
{
	for (int i = 0; i <= n; i++)
		d[0][i] = 0;
	for (int i = 0; i <= m; i++)
		d[i][0] = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (a[j] == b[i])
				d[i][j] = 1 + d[i - 1][j - 1];
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
		}
	}
	for (int i = m, j = n; (i > 0) && (j > 0);)
	{
		if (a[j] == b[i])
		{
			subsir.push_back(a[j]);
			i--;
			j--;
		}
		else if (d[i - 1][j] < d[i][j - 1])
			j--;
		else
			i--;
			
	}
}
inline void citire()
{
	ifstream fin("cmlsc.in");
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> a[i];
	for (int i = 1; i <= m; i++)
		fin >> b[i];
	fin.close();
}
inline void scriere()
{
	ofstream fout("cmlsc.out");
	fout << d[m][n] << '\n';
	while (subsir.empty() == false)
	{
		fout << subsir.back() << ' ';
		subsir.pop_back();
	}
	fout.close();
}
int main()
{
	citire();
	cmlsc();
	scriere();
	return 0;
}

