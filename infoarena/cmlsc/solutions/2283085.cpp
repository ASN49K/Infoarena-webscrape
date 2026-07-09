// CelMaiLungSubsirComun.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030][1030];
int max(int x, int y) {
	if (x > y)
		return x;
	return y;
}
void print(int i, int j) {
	if (a[i][j] != 0)
	{
		if (a[i - 1][j] == a[i][j - 1] and a[i - 1][j - 1] == a[i][j - 1] and a[i - 1][j] == a[i][j] - 1)
		{
			print(i - 1, j - 1);
			fout << a[i][0] << " ";
		}
		else
			if (a[i - 1][j] > a[i][j - 1])
				print(i - 1, j);
			else print(i, j - 1);
	}
}
int main()
{
	int n, m, lmax = 0;
	fin >> n >> m;
	for (int i = 2; i <= n + 1; i++)
		fin >> a[i][0];
	for (int j = 2; j <= m + 1; j++)
		fin >> a[0][j];
	
	
	for (int i = 2; i <= n + 1; i++)
		for (int j = 2; j <= m + 1; j++)
			if (a[i][0] == a[0][j]) 
			{
				a[i][j] = a[i - 1][j - 1] + 1;
			}
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
	fout << a[n+1][m+1] << endl;
	print(n + 1, m + 1);
}


