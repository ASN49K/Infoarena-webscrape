#include <vector>
#include <fstream>
#include <algorithm>
#define DIM 1030

using namespace std;

int dim;
int dp[DIM][DIM];
int a[DIM], b[DIM];
int n, m;
vector<int> v;

void Read()
{
	ifstream f("cmlsc.in");
	f >> n >> m;
	for (int i = 1;i <= n;++i)
		f >> a[i];
	for (int j = 1;j <= m;++j)
		f >> b[j];
	f.close();
}

void Solve()
{
	for (int i = 1;i <= n;++i)
	{
		for (int j = 1;j <= m;++j)
		{
			if (a[i] == b[j])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	dim = dp[n][m];
	int i = n, j = m;
	while (dim > 0)
	{
		if (a[i] == b[j])
		{
			v.push_back(a[i]);
			--i;
			--j;
			--dim;
		}
		else
		{
			if (dp[i - 1][j] < dp[i][j - 1])
				--i;
			else
				--j;
		}
	}
}

void Write()
{
	ofstream g("cmlsc.out");
	g << v.size() << "\n";
	for (int i = v.size() - 1;i >= 0;--i)
		g << v[i] << " ";
	g << "\n";
	g.close();
}

int main()
{
	Read();
	Solve();
	Write();
	return 0;
}