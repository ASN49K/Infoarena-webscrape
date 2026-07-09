#include <iostream>
#include <fstream>
#define NMAX 1030
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int dmax[NMAX][NMAX], a[NMAX], b[NMAX], n, m, maxm, s[NMAX];

int main () 
{
	fin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		fin >> a[i];
	}
	for (int i = 1; i <= m; ++i) {
		fin >> b[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				dmax[i][j] = dmax[i-1][j-1] + 1;
			}
			else {
				//dmax[i][j] = dmax[i-1][j-1];
				dmax[i][j] = max(dmax[i-1][j],dmax[i][j-1]);
			}
			//dmax[i][j] = max(dmax[i][j], max(dmax[i-1][j], dmax[i][j-1]));
		}
	}
	fout << dmax[n][m] << '\n';
	int ii = n, jj = m;
	while (ii && jj) {
		if (a[ii] == b[jj]) {
			s[++maxm] = a[ii];
			--ii;
			--jj;
		}
		else
		if (dmax[ii-1][jj] > dmax[ii][jj-1]) {
			--ii;
		}
		else {
			--jj;
		}
	}
	for (int i = maxm; i >= 1; --i) {
		fout << s[i] << " ";
	}
	
	return 0;
}
