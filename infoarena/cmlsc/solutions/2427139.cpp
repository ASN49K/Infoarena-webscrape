
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[1026], B[1026], D[1026][1026], sir[1026], n, m, cnt, maxim;

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
	i--;
	j--;
	maxim = D[i][j];
	fout << maxim << "\n";
	while(maxim)
	{
			if(D[i][j-1] == maxim || D[i-1][j] == maxim && j > 0)
					j--;
			else if(j == 0)
			{
				i--;
				j = m;
			}
			else
			{
					sir[++cnt] = A[i];
					i--;
					j--;
					maxim--;
			}
	}
}

int main()
{
	fin >> n >> m;
	read(n, A);
	read(m, B);
	LCS(1,1);
	for(int i = cnt; i>=1; i--)
			fout << sir[i] <<' ';
	return 0;
}
