#include<iostream>
#include<fstream>

using namespace std;

const int nMax = 1025;
const int mMax = 1025;

int x[nMax], y[mMax], n, m, M[nMax][mMax];

void citire() {
	ifstream f("cmlsc.in");
	f >> n;
	f >> m;
	int i;
	for (i = 1; i <= n; i++)
		f >> x[i];
	for (i = 1; i <= m; ++i)
		f >> y[i];
	f.close();
}

void matrice() {
	int i, j;
	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j) {
			if (x[i] == y[j]) {
				if (M[i - 1][j] < M[i][j - 1])
					M[i][j] = M[i-1][j] + 1;
				else 
					M[i][j] = M[i][j - 1] + 1;
			} else	{
				if (M[i - 1][j] > M[i][j - 1])
					M[i][j] = M[i - 1][j];
				else
					M[i][j] = M[i][j - 1];
			}
		}
}

void afisare() {
	int i = n, j = m, V[nMax], k = 0;
	ofstream g("cmlsc.out");
	g << M[i][j] << "\n";
	while (i != 0 && j != 0 && k<M[n][m]) {
		if (x[i] == y[j]) {
			V[k] = x[i];
			k++;
		}
			if (M[i][j - 1] == M[i - 1][j]) {
				i--;
				j--;
			}
		else {
			if (M[i][j - 1] < M[i - 1][j])
				i--;
			else
				j--;
		}
	}
	for (k = k-1; k >= 0; --k)
		g << V[k] << " ";
	g.close();
}

	int main(){
		citire();
		matrice();
		afisare();
		//system("pause");
		return 0;
	}