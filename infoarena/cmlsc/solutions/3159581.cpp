#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string FILE_NAME = "cmlsc";
const string input = FILE_NAME + ".in";
const string output = FILE_NAME + ".out";

ifstream fin(input);
ofstream fout(output);

vector<int> LongestCommonSubsequence(vector<int>X, vector<int>Y, int m, int n)
{
	vector<vector<int>>Dp(m+1, vector<int>(n+1, 0));
	vector<int>CMLSC;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i] == Y[j])
				Dp[i][j] = Dp[i - 1][j - 1] + 1;
			else
				Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
		}
	}

	for (int i = m, j = n; i;) {
		if (X[i] == Y[j]) {
			CMLSC.push_back(X[i]);
			--i;
			--j;
		}
		else if (Dp[i - 1][j] < Dp[i][j - 1])
			--j;
		else
			--i;

		if (i == 1)
			break;
	}

	return CMLSC;
}

int main()
{
	int m, n;

	fin >> m >> n;

	vector<int>X(m+1), Y(n+1), CMLSC;

	for (int i = 1; i <= m; i++) 
		fin >> X[i];
	for (int i = 1; i <= n; i++)
		fin >> Y[i];

	CMLSC = LongestCommonSubsequence(X, Y, m, n);

	fout << CMLSC.size() << '\n';
	for (int i = CMLSC.size() - 1; i >= 0; i--)
		fout << CMLSC[i] << ' ';

	return 0;
}