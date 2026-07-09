#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

struct
{
	int nr, poz1, poz2;
}x[1025];

int v1[1025], v2[1025];
int n, m;
int t;
int dp[1025];


int main()
{
	fin >> n >> m;
	for (int i = 1; i <= n; i++)
		fin >> v1[i];
	for (int i = 1; i <= m; i++)
		fin >> v2[i];
	for (int i = 1; i <= n; i++)
		for(int j=1;j<=m;j++)
			if (v1[i] == v2[j])
			{
				x[++t].nr = v1[i];
				x[t].poz1 = i;
				x[t].poz2 = j;

			}
	dp[1] = 1;
	for (int i = 2; i <= t; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
			if ((x[i].poz1 > x[j].poz1) && (x[i].poz2 > x[j].poz2))
				if (x[i].nr > x[j].nr)
					if (dp[j] + 1 > dp[i])
						dp[i] = dp[j] + 1;
	}
	int dpmax = 0;
	for (int i = 1; i <= t; i++)
		if (dp[i] > dpmax)
			dpmax = dp[i];
	fout << dpmax;
	return 0;
}