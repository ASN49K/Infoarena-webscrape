#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1025], B[1025], C[1025][1025];
vector<int> S;

int main()
{
	int N, M, i, j;
	fin >> N >> M;
	for (i = 1; i <= N; i++)
		fin >> A[i];
	for (i = 1; i <= M; i++)
		fin >> B[i];
	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++) {
			if (A[i] == B[j]) C[i][j] = C[i - 1][j - 1] + 1;
			else {
				if (C[i - 1][j] > C[i][j - 1]) C[i][j] = C[i - 1][j];
				else C[i][j] = C[i][j - 1];
			}
		}
	fout << C[N][M] << '\n';
	int length = C[N][M];
	for (i = N; i >= 1; i--) {
		for (j = M; j >= 1; j--) {
			if (A[i] == B[j] && C[i][j] == length) {
				length--;
				S.push_back(A[i]);
			}
		}
	}
	for (i = S.size() - 1; i >= 0; i--)
		fout << S[i] << ' ';
}

