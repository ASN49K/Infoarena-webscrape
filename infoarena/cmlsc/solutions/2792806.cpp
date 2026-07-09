#include <bits/stdc++.h>
using namespace std;

ifstream file_in("cmlsc.in");
ofstream file_out("cmlsc.out");

int a[1030], b[1030], dp[1030][1030], lcs[1030];

void citire(int& M, int& N)
{
	file_in >> M >> N;
	for (int i = 1; i <= M; ++i) file_in >> a[i];
	for (int j = 1; j <= N; ++j) file_in >> b[j];
}

int lcs_length(int lenA, int lenB)
{
	for (int i = 1; i <= lenA; ++i)
		for (int j = 1; j <= lenB; ++j)
			if (a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
	return dp[lenA][lenB];
}

int lcs_find(int lenA, int lenB)
{
	int len = 0;
	for (int i = lenA, j = lenB; i && j;)
		if (a[i] == b[j]) lcs[++len] = a[i], --i, --j;
		else if (dp[i - 1][j] > dp[i][j - 1]) --i;
		else --j;
	return len;
}

void afisare(int MAX, int len)
{
	file_out << MAX << '\n';
	for (int i = len; i >= 1; --i) file_out << lcs[i] << ' ';
}

int main()
{
	int M, N;
	citire(M, N);

	int MAX = lcs_length(M, N);
	int len = lcs_find(M, N);

	afisare(MAX, len);
	return 0;
}