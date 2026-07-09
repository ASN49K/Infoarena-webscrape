#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int const maxim = 1050;
int n, m;
int sir_1[maxim];
int sir_2[maxim];
int matrice[maxim][maxim] = { 0 };

void citire() {
	in >> n >> m;
	for (int i = 1; i <= n; i++) in >> sir_1[i];
	for (int j = 1; j <= m; j++) in >> sir_2[j];
}

void solve() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sir_1[i] == sir_2[j]) {
				matrice[i][j] = matrice[i - 1][j - 1] + 1;
			}
			else {
				matrice[i][j] = max(matrice[i - 1][j], matrice[i][j - 1]);
			}
		}
	}
}

void print_solution(int i, int j) {
	if (i != 0 && j != 0) {
		if (sir_1[i] == sir_2[j]) {
			print_solution(i-1, j-1);
			out << matrice[i][j] << " ";
		}
		else {
			if (matrice[i - 1][j] > matrice[i][j - 1]) print_solution(i - 1, j);
			else print_solution(i, j - 1);
		}
	}
} 


int main()
{
	citire();
	solve();
	out << matrice[n][m] << '\n';
	print_solution(n, m);
	return 0;
}
