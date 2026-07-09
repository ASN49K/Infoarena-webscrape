//============================================================================
// Name        : cmlsc.cpp
// Author      : Margineanu Cristian
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <fstream>
#define INF 1024
#define maxv(a, b) (a > b ? a : b)
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[INF + 1], b[INF + 1], c[INF + 1]; // a - primul sir, b - al doilea sir, c - sirul rezultat dupa calcule
int t[INF + 1][INF + 1];

int main() {
	int m, n; // m = nr de elemente din sirul a, n = nr de elemente din sirul b
	fin >> m >> n;
	for (int i = 1; i <= m; i++)
		fin >> a[i];
	for (int i = 1; i <= n; i++)
		fin >> b[i];
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++)
			if (a[i] == b[j])
				t[i][j] = t[i-1][j-1] + 1;
			else
				t[i][j] = maxv(t[i-1][j], t[i][j-1]);
	int aux = t[m][n];
	t[0][0] = aux;
	int poz = 1;
	while (aux > 0){
		if (t[m][n] == t[m-1][n])
			m -= 1;
		else
			if (t[m][n] == t[m][n-1])
				n -= 1;
			else{
				c[poz++] = a[m];
				m -= 1;
				n -= 1;
				aux -= 1;
			}
	}
	fout << t[0][0] << '\n';
	for (int i = t[0][0]; i >= 1; i--)
		fout << c[i] << ' ';
	return 0;
}
