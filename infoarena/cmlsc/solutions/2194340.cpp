#include <iostream>
#include <fstream>
#include <unordered_set>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024

int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;

int main(void)
{
	int i, j;

	fin >> M >> N;

	FOR(i, 1, M)
		fin >> A[i];
	FOR(i, 1, N)
		fin >> B[i];

	FOR(i, 1, M)
		FOR(j, 1, N)
		if (A[i] == B[j])
			D[i][j] = 1 + D[i - 1][j - 1];
		else
			D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);

	for (i = M, j = N; i; )
		if (A[i] == B[j])
			sir[++bst] = A[i], --i, --j;
		else if (D[i - 1][j] < D[i][j - 1])
			--j;
		else
			--i;

	fout << bst << '\n';
	for (i = bst; i; --i)
		fout << sir[i] << ' ';

	return 0;
}