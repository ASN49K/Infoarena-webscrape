#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int const maxim = 1029;

int matrice[maxim][maxim] = { 0 };
int sir_1[maxim] = { 0 };
int sir_2[maxim] = { 0 };

int n, m;


void trace_back(int i, int j) {
	if (i && j) {
		if (sir_1[i] == sir_2[j]) {
			trace_back(i - 1, j - 1);
			out << sir_1[i] << " ";
		}
		else if(matrice[i-1][j] > matrice[i][j-1]) {
			trace_back(i - 1, j);
		}
		else {
			trace_back(i, j - 1);
		}
	}
}

int main() {
	in >> n >> m;
	for (int i = 1; i <= n; i++) {
		in >> sir_1[i];
	}
	for (int i = 1; i <= m; i++) {
		in >> sir_2[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sir_1[i] == sir_2[j]) matrice[i][j] = matrice[i - 1][j - 1] + 1;
			else matrice[i][j] = max(matrice[i - 1][j], matrice[i][j - 1]);
		}
	}
	out << matrice[n][m] << endl;
	trace_back(n, m);
	return 0;
}