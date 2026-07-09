#include <fstream>
#include <iostream>
using namespace std;

unsigned int lcsl[1025][1025];
short unsigned int a[1025];
short unsigned int b[1025];
short unsigned int s[1025];
int n, m;

void lcs(int i, int j)
{
	if (i == 0 || j == 0)
	{
		lcsl[i][j] = 0;
	}
	else if (a[i] == b[j])
	{
		lcs(i-1, j-1);
		lcsl[i][j] = lcsl[i-1][j-1]+1;
		s[lcsl[i][j]] = a[i];
	}
	else
	{
		lcs(i-1, j);
		lcs(i, j-1);
		lcsl[i][j] = max(lcsl[i-1][j], lcsl[i][j-1]);
	}
}
int main()
{
	ifstream fin("cmlcs.in");
	ofstream fout("cmlcs.out");
	fin >> n >> m;
	for (int i=1; i<=n; i++)
		fin >> a[i];
	for (int i=1; i<=m; i++)
		fin >> b[i];
	lcs(n, m);
	fout << lcsl[n][m] << "\n";
	for (int i=1; i<=lcsl[n][m]; i++)
		fout << s[i] << " ";
	fin.close();
	fout.close();
	return 0;
}

