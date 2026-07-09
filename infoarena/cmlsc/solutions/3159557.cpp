#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const string FILE_NAME = "cmlsc";
const string input = FILE_NAME + ".in";
const string output = FILE_NAME + ".out";

ifstream fin(input);
ofstream fout(output);

int m, n;
vector<int>X, Y, CMLSC;
vector<vector<int>>DP;

void LongestCommonSubsequence()
{
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (X[i] == Y[j]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	int i = m, j = n;

	do
	{
		if (X[i] == Y[j]) {
			CMLSC.push_back(X[i]);
			i--;
			j--;
		}
		else if (DP[i - 1][j] < DP[i][j - 1])
			j--;
		else
			i--;
	} while (i > 1);
}

int main()
{
	fin >> m >> n;

	X = vector<int>(m+1);
	Y = vector<int>(n+1);
	
	for (int i = 1; i <= m; i++) fin >> X[i];
	for (int i = 1; i <= n; i++) fin >> Y[i];

	DP = vector<vector<int>>(m+1, vector<int>(n+1, 0));

	LongestCommonSubsequence();

	fout << CMLSC.size() << '\n';
	for (int i = CMLSC.size() - 1; i >= 0; i--)
		fout << CMLSC[i] << ' ';

	return 0;
}