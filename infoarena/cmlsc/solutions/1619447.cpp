#include <iostream>
#include <fstream>

#define NMAX 1024
#define max(a, b) ((a > b) ? a : b)

int A[NMAX], B[NMAX], L[NMAX][NMAX];
int N, M;

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int max_length() {
	for (int i = 0; i <= M; i++) {
		for (int j = 0; j <= N; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;
			else if (A[i-1] == B[j-1]) 
				L[i][j] = 1 + L[i-1][j-1];
			else 
				L[i][j] = max(L[i-1][j], L[i][j-1]);
		}
	}

	return L[M][N];
}

int main() {
	fin >> M >> N;
	for (int i = 0; i < M; i++) {
		fin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		fin >> B[i];
	}

	fout << max_length() << '\n';

	return 0;
}