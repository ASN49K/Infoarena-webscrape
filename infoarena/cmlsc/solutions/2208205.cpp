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


int N, M;
int arr1[1024], arr2[1024];
int matrix[10][10];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	fin >> N >> M;
	for (int i = 0; i < N; i++) {
		fin >> arr1[i];
	}
	for (int i = 0; i < M; i++) {
		fin >> arr2[i];
	}

	int seq[1024], index = 0;
	for (int row = 0; row <= N; ++row) {
		for (int col = 0; col <= M; ++col)
		{
			if (row == 0 || col == 0)
				matrix[row][col] = 0;
			else if (arr1[row - 1] == arr2[col - 1]) {
				matrix[row][col] = 1 + matrix[row - 1][col - 1];
				seq[index++] = arr1[row - 1];
			}
			else
				matrix[row][col] = max(matrix[row - 1][col], matrix[row][col - 1]);
		}
	}
	fout << matrix[N][M];

	fout << "\n";
	for (int i = 0; i < matrix[N][M]; i++) {
		fout << seq[i] << " ";
	}

	system("pause");

}