#include<fstream>
//#include<pch.h>
using namespace std;
#define LMAX 1024
#define max(a, b) (a > b ? a : b)

int sol[LMAX][LMAX], A[LMAX], B[LMAX], i, j, M, N;

void longestCommonSubstring() {
	for (i = 1; i <= M; ++i) {
		for (j = 1; j <= N; ++j) {
			if (A[i] != B[j]) {
				sol[i][j] = max(sol[i][j - 1], sol[i - 1][j]);
			}
			else {
				sol[i][j] = sol[i - 1][j - 1] + 1;
			}
		}
	}
}

void printSolution(int i, int j, ofstream &fout) {

	if(i > 0 && j > 0) {
		if (A[i] == B[j]) {
			printSolution(i - 1, j - 1, fout);
			fout << A[i] << " ";
		}
		else if (sol[i - 1][j] == sol[i][j] && i > 0) {
			printSolution(i - 1, j, fout);
		}
		else if(sol[i][j-1] == sol[i][j] && j > 0){
			printSolution(i, j - 1, fout);
		}
	}
}

void readDataAndCompute(ifstream &fin, ofstream &fout) {
	fin >> M >> N;
	for (i = 1; i <= M; ++i) {
		fin >> A[i];
	}
	for (i = 1; i <= N; ++i) {
		fin >> B[i];
	}

	longestCommonSubstring();
	fout << sol[M][N] << "\n";
	printSolution(M, N, fout);
}
int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	readDataAndCompute(fin, fout);
	fin.close();
	fout.close();
	return 0;
}