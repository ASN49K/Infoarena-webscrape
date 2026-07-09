// CelMaiLungSubsirComun.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1024][1024];
int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}
int main()
{
	int n, m, lmax=0;
	fin >> n >> m;
	int sol[1024];
	for (int i = 1; i <= n; i++)
		fin >> a[i][0];
	for (int j = 1; j <= m; j++)
		fin >> a[0][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][0] == a[0][j]) {
				a[i][j] = max(a[i - 1][j], a[i][j - 1]) + 1;

				sol[++lmax]=a[i][0];
			}
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
	fout << lmax << "\n";
	for (int i = 1; i <= lmax; i++)
		fout << sol[i] << " ";
}

