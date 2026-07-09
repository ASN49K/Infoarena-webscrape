// Infoarena.cpp : Defines the entry point for the console application.
//

#include <fstream>

#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
unsigned short L[1024][1024];
void generareLCS(unsigned short *X, unsigned short *Y, int m, int n)
{
	int i, j;

	/* Following steps build L[m+1][n+1] in bottom up fashion. Note
	that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
	for (i = 0; i <= m; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (X[i - 1] == Y[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;

			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);
		}
	}
}
void afisareLCS(unsigned short *X, unsigned short *Y, const int m, const int n)
{

	int index = L[m][n]; 
	unsigned short *lcs = new unsigned short[L[m][n]];
	int i = m, j = n;
	while (i > 0 && j > 0)
	{
		// If current character in X[] and Y are same, then
		// current character is part of LCS
		if (X[i - 1] == Y[j - 1])
		{
			lcs[index - 1] = X[i - 1]; // Put current character in result
			i--; j--; index--;     // reduce values of i, j and index
		}

		// If not same, then find the larger of two and
		// go in the direction of larger value
		else if (L[i - 1][j] > L[i][j - 1])
			i--;
		else
			j--;
	}
	for (unsigned short i = 0; i < L[m][n]; i++)
		fout << lcs[i]<<" ";
}
int main()
{
	unsigned short n,m;
	fin >> m >> n;
	unsigned short *X = new unsigned short[n];
	unsigned short *Y = new unsigned short[m];
	//citire
	for (unsigned i = 0; i < m; i++)
		fin >> X[i];
	for (unsigned i = 0; i < n; i++)
		fin >> Y[i];
	generareLCS(X, Y, m, n);
	fout << L[m][n]<<"\n";
	afisareLCS(X,Y,m,n);
    return 0;
}

