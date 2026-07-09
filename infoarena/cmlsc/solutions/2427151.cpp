
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1024], B[1024], D[1024][1024], sir[1024], n, m, cnt, maxim;

void read(int n, int v[])
{
	for(int i = 1; i<=n; i++)
			fin >> v[i];
}

void LCS(int i, int j)
{
	for(i = 1; i<=n; i++)
	{
			for(j = 1; j<=m; j++)
			{
			 if(A[i] == B[j])
							D[i][j] = 1 + D[i-1][j-1];
					else
							D[i][j] = max(D[i-1][j], D[i][j-1]);
			}
	}
	for(i = m, j = n; i ;)
		if(A[i] == B[j])
			sir[++cnt] = A[i], --i, --j;
		else if(D[i-1][j] < D[i][j-1])
			--j;
			else
			--i;
}

int main()
{
	fin >> n >> m;
	read(n, A);
	read(m, B);
	LCS(1,1);
	fout << cnt <<"\n";
	for(int i = cnt; i>=1; i--)
			fout << sir[i] <<' ';
	return 0;
}
