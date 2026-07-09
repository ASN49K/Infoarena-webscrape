#include <fstream>
#include <stack>
#include <iostream>

#define nmax 1030

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

stack <int> S;

void citire(int &n, int a[])
{
	fin >> n;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
}

int maxim(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

void programare_dinamica(int m, int a[], int n, int b[], int mat[][nmax])
{
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j)
			if (a[i] == b[j])
				mat[i][j] = mat[i - 1][j - 1] + 1;
			else
				mat[i][j] = maxim(mat[i - 1][j], mat[i][j - 1]);
}

void afisare(int m, int a[], int n, int b[], int mat[][nmax])
{
	fout << mat[n][m] << "\n";
	int v = mat[n][m];
	int i = m, j = n;
	while (i > 0 && j > 0)
		if (mat[i - 1][j] == v - 1 && mat[i][j - 1] == v - 1)
			S.push(a[i]);
		else
			if (mat[i - 1][j] == v)
				--i;
			else
				--j;
	while (!S.empty())
	{
		fout << S.top() << " ";
		S.pop();
	}
}

int main()
{
	int m, n, a[nmax], b[nmax];
	int mat[nmax][nmax] = { 0 };
	citire(m, a);
	citire(n, b);
}