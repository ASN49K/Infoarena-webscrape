#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	int m, n;
	int v[1024], w[1024], rez[2014];
	int i, j;
	int max = 0, lung = 0, pozJ = 0, stop = 0;
	fin >> m >> n;
	for (i = 0; i < m; i++) { fin >> v[i]; }
	for (i = 0; i < n; i++) { fin >> w[i]; }

	for (i = 0; i < m; i++)
	{
		stop = 0;
		for (j = pozJ; j < n && stop == 0; j++)
		{
			if (v[i] == w[j])
			{
				rez[lung++] = v[i];
				stop = 1;
				pozJ = j + 1;
			}
		}
	}
	fout << lung << "\n";
	for (i = 0; i < lung; i++)
	{
		fout << rez[i] << " ";
	}

	return 0;
}