#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
void print(int a[][10],int n,int m)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}
int main()
{
	int n, m, a[1024], b[1024],i,s[1024][1024],j;
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	fin >> n >> m;
	for (i = 0; i < n; i++)
		fin >> a[i];
	for (i = 0; i < m; i++)
		fin >> b[i];

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= m; j++)
		{
			if (i == 0 || j == 0)
				s[i][j] = 0;
			else if (a[i - 1] == b[j - 1])
				s[i][j] = 1 + s[i - 1][j - 1];
			else
				s[i][j] = max(s[i-1][j],s[i][j-1]);
		}
	}
	//print(s, n, m);
	//cout << s[n][m];

	fout << s[n][m] << endl;
	int x[1024];
	int k = s[n][m] - 1;
	for (i = n, j = m; i > 0;)
	{
		if (a[i-1] == b[j-1])
		{
			x[k--] = a[i - 1];
			i--;
			j--;
		}
		else if (s[i - 1][j] > s[i][j - 1])
			i--;
		else
			j--;
	}
	for (i = 0; i < s[n][m]; i++)
	{
		fout << x[i] << " ";
	}
}