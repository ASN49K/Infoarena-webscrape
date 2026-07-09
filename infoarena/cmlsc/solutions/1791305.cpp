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
	for (int i = 1; i <= n; ++i) {
		fin >> b[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (a[i] == b[j]) {
				dmax[i][j] = dmax[i-1][j-1] + 1;
			}
			else {
				dmax[i][j] = dmax[i-1][j-1];
			}
			dmax[i][j] = max(dmax[i][j], max(dmax[i-1][j], dmax[i][j-1]));
		}
	}
	fout << dmax[n][m] << '\n';
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			if (dmax[i][j] > maxm) {
				maxm = dmax[i][j];
				s[maxm] = a[i];
			}
		}
	}
	for (int i = 1; i <= maxm; ++i) {
		fout << s[i] << " ";
	}
	
	return 0;
}
