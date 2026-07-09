#include <iostream>
#include <fstream>
using namespace std;
#define NMAX 1024
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[NMAX];
int b[NMAX];
int sol[NMAX];
int solSize;

void findSol(int* solAux, int pos, int* a, int* b, int posA, int posB, int sizeA, int sizeB);

void finSolUtil(int* solAux, int* a, int*b, int sizeA, int sizeB);

int main() {
	int sizeA;
	int sizeB;
	fin >> sizeA;
	fin >> sizeB;
	int solAux[NMAX];
	for (int i = 0; i < sizeA; ++i) {
		fin >> a[i];
	}
	for (int i = 0; i < sizeB; ++i) {
		fin >> b[i];
	}
	fin.close();
	finSolUtil(solAux, a, b, sizeA, sizeB);
	fout << solSize << '\n';
	for (int i = 0; i < solSize; ++i) {
		fout << sol[i] << ' ';
	}
	fout.close();
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
				findSol(solAux, pos + 1, a, b, j + 1, i + 1, sizeA, sizeB);
			}
		}
		j = posB;
	}
}