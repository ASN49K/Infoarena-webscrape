#include<fstream>
#include<vector>

#define NMAX 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[NMAX], b[NMAX], n, m, DP[2][NMAX];
vector<int> listX[NMAX], listY[NMAX], sol;

int main()
{
	fin >> n >> m;
	for(int i = 1; i <= n; i++)
		fin >> a[i];
	for(int i = 1; i <= m; i++)
		fin >> b[i];
	
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
				if(M == NMAX || M == DP[1 - l][j])
				{
					M = DP[1 - l][j];
					listX[M].push_back(i);
					listY[M].push_back(j);
				}
	}
	fout<<DP[l][m]<<"\n";
	
	int X = (1<<30), Y = (1<<30);
	
	for(int i = DP[l][m]; i; i--)
		for(size_t j = 0; j < listX[i].size(); j++)
			if(X > listX[i][j] && Y > listY[i][j])
			{
				X = listX[i][j];
				Y = listY[i][j];
				sol.push_back(a[X]);
				break;
			}
	for(int i = sol.size() - 1; i >= 0; i--)
		fout << sol[i] << " ";
	return 0;
}
