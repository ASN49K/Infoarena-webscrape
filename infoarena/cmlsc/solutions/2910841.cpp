#include <iostream>
#include <fstream>
#include <string>

#define NMAX 1024

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int M, N;
int A[NMAX+1], B[NMAX+1];
int DP[NMAX+1][NMAX+1];

string bkt(int table[][NMAX+1], int s1[], int s2[], int i, int j) {
	if (i == 0 || j == 0)
		return "";
	if (s1[i] == s2[j])
		return bkt(table, s1, s2, i-1, j-1) + to_string(s1[i]) + " ";
	if (table[i][j-1] > table[i-1][j])
		return bkt(table, s1, s2, i, j-1);
	return bkt(table, s1, s2, i-1, j);
}

void setup() {
	f >> M >> N;
	for (int i = 1; i <= M; i++)
		f >> A[i];
	for (int i = 1; i <= N; i++)
		f >> B[i];

	for (int i = 0; i <= M; i++)
		DP[i][0] = 0;
	for (int i = 0; i <= N; i++)
		DP[0][i] = 0;
}

int main() {
	setup();

	for (int i = 1; i <= M; i++)
		for (int j = 1; j <= N; j++) {
			if (A[i] == B[j])
				DP[i][j] = DP[i-1][j-1] + 1;
			else
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}

	g << DP[M][N] << '\n';
	g << bkt(DP, A, B, M, N);

	return 0;
}
