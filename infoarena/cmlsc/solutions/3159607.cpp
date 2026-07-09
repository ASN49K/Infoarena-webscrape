#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string FILE_NAME = "cmlsc";
const string input = FILE_NAME + ".in";
const string output = FILE_NAME + ".out";

ifstream fin(input);
ofstream fout(output);

vector<int>LongestCommonSubsequence(vector<int>X, vector<int>Y) 
{
	int n = X.size() - 1, m = Y.size() - 1;
	vector<int> sol;
	vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (X[i] == Y[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	int i = n, j = m;

	while (i && j)
	{
		if (X[i] == Y[j]) {
			sol.push_back(X[i]);
			i--;
			j--;
		}
		else {
			if (dp[i - 1][j] < dp[i][j - 1])
				j--;
			else
				i--;
		}
	}

	return sol;
}

int main()
{
	int n, m;
	vector<int>X, Y, LCS;

	fin >> n >> m;

	X = vector<int>(n + 1);
	Y = vector<int>(m + 1);

	for (int i = 1; i <= n; i++)
		fin >> X[i];
	for (int i = 1; i <= m; i++)
		fin >> Y[i];

	LCS = LongestCommonSubsequence(X, Y);

	fout << LCS.size() << '\n';
	for (vector<int>::reverse_iterator it = LCS.rbegin(); it != LCS.rend(); it++)
		fout << *it << ' ';

	return 0;
}