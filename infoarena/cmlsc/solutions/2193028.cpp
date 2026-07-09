#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int getLcs(vector<int> &A, vector<int> &B, int lcsMatrix[1025][1025]) {
	for (int i = 0; i <= A.size(); ++i)
		lcsMatrix[0][i] = 0;

	for (int i = 0; i <= B.size(); ++i)
		lcsMatrix[i][0] = 0;

	for (int i = 1; i <= B.size(); ++i) {
		for (int j = 1; j <= A.size(); ++j) {
			if (A[j - 1] == B[i - 1]) {
				lcsMatrix[i][j] = lcsMatrix[i - 1][j - 1] + 1;
			} else {
				lcsMatrix[i][j] = max(lcsMatrix[i - 1][j], lcsMatrix[i][j - 1]);
			}
		}
	}

	return lcsMatrix[B.size()][A.size()];
}
void reconstructLcsFromMatrix(vector<int> &A, vector<int> &B, int lcsMatrix[1025][1025]) {
	deque<int> reconstructedRoad;
	int i = B.size();
	int j = A.size();

	while (i != 0 && j != 0) {
		if (A[j - 1] == B[i - 1]) {
			reconstructedRoad.push_front(A[j - 1]);
			i--; j--;
			continue;
		}

		if (lcsMatrix[i - 1][j] > lcsMatrix[i][j - 1]) {
			i--;
		} else {
			j--;
		}
	}
	
	for (int i = 0; i < reconstructedRoad.size(); ++i) {
		fout << reconstructedRoad[i] << ' ';
	}

	fout << '\n';
}

int main() {
	int M, N;
	int lcsMatrix[1025][1025];
	
	fin >> M >> N;

	vector<int> A(M);
	vector<int> B(N);

	for (int i = 0; i < M; ++i) 
		fin >> A[i];
	for (int i = 0; i < N; ++i) 
		fin >> B[i];

	fout << getLcs(A, B, lcsMatrix) << '\n';
	reconstructLcsFromMatrix(A, B, lcsMatrix);

	return 0;
}