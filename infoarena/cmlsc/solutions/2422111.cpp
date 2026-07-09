#include <iostream>
#include <fstream>
using namespace std;
#define MAX_SIZE 1024
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int dpSize[MAX_SIZE][MAX_SIZE];
int dpSol[MAX_SIZE];
int solSize;

int getMax(int a, int b);

void computeLength(int* x, int xSize, int* y, int ySize);

void getSol(int* x, int xSize, int* y, int ySize);

int main() {
	for (int i = 0; i < MAX_SIZE; ++i) {
		for (int j = 0; j < MAX_SIZE; ++j) {
			dpSize[i][j] = 0;
		}
	}
	int n;
	int m;
	int a[MAX_SIZE];
	int b[MAX_SIZE];
	fin >> m;
	fin >> n;
	for (int i = 1; i <= m; ++i) {
		fin >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		fin >> b[i];
	}
	solSize = 0;
	computeLength(a, m, b, n);
	getSol(a, m, b, n);
	fout << solSize << '\n';
	for (int i = solSize - 1; i >= 0; --i) {
		fout << dpSol[i] << ' ';
	}
	return 0;
};

int getMax(int a, int b) {
	if (a > b) {
		return a;
	}
	return b;
}


void computeLength(int* x, int xSize, int* y, int ySize) {
	for (int i = 1; i < xSize; ++i) {
		for (int j = 1; j < ySize; ++j) {
			if (x[i] == y[j]) {
				dpSize[i][j] = dpSize[i - 1][j - 1] + 1;
			}
			else {
				dpSize[i][j] = getMax(dpSize[i - 1][j], dpSize[i][j - 1]);
			}
		}
	}
}

void getSol(int* x, int xSize, int* y, int ySize) {
	int i = xSize;
	int j = ySize;
	while (i > 0 && j > 0) {
		if (x[i] == y[j]) {
			dpSol[solSize++] = x[i--];
			j--;
		}
		else if (dpSize[i][j - 1] < dpSize[i - 1][j]) {
			i--;
		}
		else {
			j--;
		}
	}
}