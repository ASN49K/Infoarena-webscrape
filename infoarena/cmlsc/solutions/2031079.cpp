#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int LCS(vector<int> a, vector<int> b, int na, int nb, vector<int>& seq)
{
	vector<vector<int>> dp(na + 1, vector<int>(nb + 1, 0));

	for (int i = 0; i <= na; i++)
	{
		for (int j = 0; j <= nb; j++)
		{
			if (i == 0 || j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				int val1 = 0;
				if (a[i - 1] == b[j - 1])
				{
					val1 = 1 + dp[i - 1][j - 1];
				}
				dp[i][j] = max(val1, max(dp[i - 1][j], dp[i][j - 1]));
			}		
		}
	}
	int pa = na, pb = nb;
	while (pa > 0 && pb > 0)
	{
		int npa = pa - 1, npb = pb;
		if (dp[pa][pb - 1] > dp[npa][npb])
		{
			npa = pa;
			npb = pb - 1;
		}
		if (a[pa - 1] == b[pb - 1] && 1 + dp[pa - 1][pb - 1] > dp[npa][npb])
		{
			npa = pa - 1;
			npb = pb - 1;
			seq.push_back(a[pa - 1]);
		}
		pa = npa;
		pb = npb;
	}
	return dp[na][nb];
}
void ReadVector(vector<int>& v, int n)
{
	for (int i = 0; i < n; i++)
	{
		in >> v[i];
	}
}
int main()
{
	int M, N;
	in >> M >> N;
	vector<int> a(M, 0);
	vector<int> b(N, 0);
	ReadVector(a, M);
	ReadVector(b, N);
	vector<int> seq;
	out << LCS(a, b, M, N, seq) << '\n';
	for (auto it = seq.rbegin(); it != seq.rend(); it++)
	{
		out << *it << ' ';
	}
}