#include <fstream>
using namespace std;


int c[1025][1025];
int X[1025];
int Y[1025];


	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");

void print(int n, int m)
{
	if ((n >= 1 && m >= 1))
	{
		if (c[n][m] > c[n - 1][m - 1] && c[n][m] > c[n - 1][m] && c[n][m] > c[n][m - 1])
		{
			print(n - 1, m - 1);
			fout << X[n] << ' ';
		}
		else
		{
			if (c[n - 1][m] > c[n][m - 1])
			{

				print(n - 1, m);
			}
			else
			{
				print(n, m - 1);
			}
		}
	}
	else
	{
		if (X[n] == Y[m])
		{

		}
		fout << '\n';
	}
		
}



int main()
{
	int n, m;
	fin >> n>> m;
	for (int i = 1; i <= n; i++)
	{
		fin >> X[i];
	}
	for (int i = 1; i <= m; i++)
	{
		fin >> Y[i];
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
			{
				c[i][j] = 0;
			}
			else
				if (X[i] == Y[j])
				{
					c[i][j] = c[i - 1][j - 1]+1;
				}
				else
				if (c[i - 1][j] >= c[i][j - 1])
					c[i][j] = c[i - 1][j];
				else
					c[i][j] = c[i][j - 1];
		}
	}
	fout << c[n][m]<<'\n';
	print(n, m);
}