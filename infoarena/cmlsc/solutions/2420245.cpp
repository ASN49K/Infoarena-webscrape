#include <iostream>
#include <fstream>
using namespace std;

#define MAX_SIZE 256
fstream fin("cmlsc.in");
fstream fout("cmlsc.out");
int* sol;
int solSize;

void findSol(int* solAux, int pos, int* a, int* b, int posA, int posB, int sizeA, int sizeB);

void finSolUtil(int* solAux, int* a, int*b, int sizeA, int sizeB);

int main() {
	solSize = 0;
	int sizeA;
	int sizeB;
	fin >> sizeA;
	fin >> sizeB;
	int* a = (int*)malloc(sizeof(int) * sizeA);
	int* b = (int*)malloc(sizeof(int) * sizeB);
	sol = (int*)malloc(sizeof(int) * sizeB);
	int* solAux = (int*)malloc(sizeof(int) * sizeB);
	for (int i = 0; i < sizeA; ++i) {
		fin >> a[i];
	}
	for (int i = 0; i < sizeB; ++i) {
		fin >> b[i];
	}
	finSolUtil(solAux, a, b, sizeA, sizeB);
	fout << solSize << '\n';
	for (int i = 0; i < solSize; ++i) {
		fout << sol[i] << ' ';
	}
	free(a);
	free(b);
	free(sol);
	free(solAux);
	return 0;
}

void finSolUtil(int* solAux, int* a, int*b, int sizeA, int sizeB) {
	if (sizeA > sizeB) {
		findSol(solAux, 0, a, b, 0, 0, sizeA, sizeB);
	}
	else {
		findSol(solAux, 0, b, a, 0, 0, sizeB, sizeA);
	}
}

void findSol(int* solAux, int pos, int* a, int* b, int posA, int posB, int sizeA, int sizeB) {
	if (solSize < pos) {
		solSize = pos;
		for (int i = 0; i < solSize; ++i) {
			sol[i] = solAux[i];
		}
	}
	int i = posB;
	int j = posA;
	for (; i < sizeB; ++i) {
		for (; j < sizeA; ++j) {
			if (b[i] == a[j]) {
				solAux[pos] = b[i];
				findSol(solAux, pos + 1, a, b, i + 1, j + 1, sizeA, sizeB);
			}
		}
		j = posB;
	}
}