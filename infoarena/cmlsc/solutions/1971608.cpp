#include <iostream>
#include <fstream>
#define Nmax 1024
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m, n, a[Nmax], b[Nmax], subsir[Nmax];

int main()
{
	f >> m >> n;
	for (int i = 0; i < m; i++)
	{
		f >> a[i];
	}
	for (int j = 0; j < n; j++)
	{
		f >> b[j];
	}
	int k = 0;

	for(int i=0;i<m;i++)
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				subsir[k] = a[i];
				k++;
			}
		}
	g << k<<'\n';
	for (int i = 0; i < k; i++)
	{
		g << subsir[i];
	}
	system("pause");
	return 0;
}