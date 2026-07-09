#include<fstream>
#include<cstring>

#define NMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NMAX], b[NMAX], n, m, DP[2][NMAX], pos[NMAX];

int main()
{
	fin >> n >> m;
	for(int i = 1; i <= n; i++)
		fin >> a[i];
	for(int i = 1; i <= m; i++)
		fin >> b[i];
	memset(pos, 127, 4 * NMAX);
	
	int l = 0, M;
	for(int i = 1; i <= n; i++, l = 1 - l)
	{
		for(int j = 1; j <= m; j++)
			if(a[i] == b[j])
				DP[1 - l][j] = DP[l][j - 1] + 1;
			else
				DP[1 - l][j] = max(DP[1 - l][j - 1], DP[l][j]);
		M = NMAX;
		for(int j = m; j; j--)
			if(a[i] == b[j])
				if(pos[DP[1 - l][j]] > j && (M == NMAX || M == DP[1 - l][j]))
				{
					M = DP[1 - l][j];
					pos[M] = j;
				}
	}
	fout<<DP[l][m]<<"\n";
	for(int i = 1; i <= DP[l][m]; i++)
		fout<<b[pos[i]]<<" ";
	return 0;
}
