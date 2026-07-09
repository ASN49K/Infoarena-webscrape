#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int NMAX = 1024;

int dp[1 + NMAX][1 + NMAX];
int A[1 + NMAX], B[1 + NMAX];
int N, M;

void getSolution(int N, int M) {

	if (N * M == 0) return ;

	if (A[N] == B[M]) {

		getSolution(N - 1, M - 1);
		fout << A[N] << ' ';
	}
	else {

		if (dp[N - 1][M] > dp[N][M - 1])
			getSolution(N - 1, M);
		else getSolution(N, M - 1);
	}
}

int main() {

	fin >> N >> M;

	for (int idx = 1; idx <= N; ++idx) fin >> A[idx];
	for (int idx = 1; idx <= M; ++idx) fin >> B[idx];

	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			if (A[i] == B[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

	fout << dp[N][M] << '\n';

	getSolution(N, M);
}