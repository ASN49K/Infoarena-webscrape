#include <fstream>
#include <iostream>
#include <string>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


#define N 1025
int v1[N], v2[N];
int matrix[N][N];

int max(int a, int b) {
	if (a > b) return a;
	else return b;
}

void getSoltion(int mat[N][N], int lin, int col) {
	if (lin > 0 && col > 0) {
		if (v1[lin] == v2[col]) {
			getSoltion(mat, lin - 1, col - 1);
			g << v1[lin] << " ";
		}
		else {
			if (mat[lin - 1][col] > mat[lin][col - 1]) {
				getSoltion(mat, lin - 1, col);
			}
			else {
				getSoltion(mat, lin, col - 1);
			}
		}
	}
}

int main()
{
	int lgV1, lgV2;
	f >> lgV1 >> lgV2;
	for (int i = 1; i <= lgV1; ++i) {
		f >> v1[i];
	}
	for (int i = 1; i <= lgV2; ++i) {
		f >> v2[i];
	}

	for (int i = 1; i <= lgV1; ++i) {	
		for (int j = 1; j <= lgV2; ++j) {
			if (v1[i] == v2[j]) {
				matrix[i][j] = matrix[i - 1][j - 1] + 1; //we can do this bc I will not use position 0 from the matrix
			}
			else {
				matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	g << matrix[lgV1][lgV2] << "\n";
	getSoltion(matrix, lgV1, lgV2);
	return 0;
}