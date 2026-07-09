#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");


int main() {
	int a[100], b[100], m, n, c[100], nr = 0;
	fin >> m >> n;

	for (int i = 1; i <= m; i++)
		fin >> a[i];
	for (int i = 1; i <= n; i++)
		fin >> b[i];

	int f = 1;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j])
			{
				nr++;
				c[f] = a[i];
				f++;
			}
	fout << nr << "\n";

	for (int i = 1; i <= nr; i++)
		fout << c[i] << " ";

	return 0;

}