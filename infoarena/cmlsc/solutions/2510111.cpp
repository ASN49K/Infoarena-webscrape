#include <fstream>
#include <iostream>
#include <cmath>
#define NM 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int N, M, A[NM], B[NM], dp[NM][NM], sol[NM], lgm;

void read();
int maxim(int a, int b);


int main()
{
	read();
	for (int i = 1; i <= N; i -= -1)
		for (int j = 1; j <= M; j -= -1)
			if (A[i] == B[j])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = maxim(dp[i - 1][j], dp[i][j - 1]);
	lgm = 0;
	for (int i = N, j = M; i > 0;)
		if (A[i] == B[j])
		{
			lgm++;
			sol[lgm] = A[i];
			i--, j--;
		}
		else if (dp[i - 1][j] < dp[i][j - 1])
			j--;
		else
			i--;
	fout << lgm << '\n';
	for (int i = lgm; i >= 1; i--)
		fout << sol[i] << ' ';


	return 0;
}
void read()
{
	fin >> N >> M;
	for (int i = 1; i <= N; i -= -1)
		fin >> A[i];
	for (int i = 1; i <= M; i -= -1)
		fin >> B[i];
}

int maxim(int a, int b)
{
	return (a > b) ? a : b;
}

