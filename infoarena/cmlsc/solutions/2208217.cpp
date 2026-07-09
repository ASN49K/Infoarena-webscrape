#include <cmath>
#include <cstdio>
#include <map>
#include <assert.h>
#include <cassert>
#include <iomanip>
#include <set>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max(int a, int b) { return a > b ? a : b; }
int N, M, arr1[2025], arr2[2025], matrix[2025][2025], seq[2025];
int main() {
	fin >> N >> M;
	for (int i = 0; i < N; i++) {
		fin >> arr1[i];
	}
	for (int i = 0; i < M; i++) {
		fin >> arr2[i];
	}

	int index = 0;
	for (int row = 0; row <= N; ++row) {
		for (int col = 0; col <= M; ++col)
		{
			if (row == 0 || col == 0)
				matrix[row][col] = 0;
			else if (arr1[row - 1] == arr2[col - 1]) {
				matrix[row][col] = 1 + matrix[row - 1][col - 1];
			}
			else
				matrix[row][col] = max(matrix[row - 1][col], matrix[row][col - 1]);
		}
	}
	fout << matrix[N][M];

	fout << "\n";
	int i = N, j = M;
	while (i > 0 && j > 0) {
		if (arr1[i - 1] == arr2[j - 1]) {
			seq[index] = arr1[i - 1];
			--i, --j, ++index;
		}
		else {
			if (matrix[i - 1][j] >= matrix[i][j - 1]) {
				--i;
			}
			else
				--j;
		}

	}
	
	for (int k = matrix[N][M] - 1; k>=0; --k) {
		fout << seq[k] << " ";
	}

	system("pause");

	return 0;
}
