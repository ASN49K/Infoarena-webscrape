#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int m, n, a[1025], b[1025], c[1025], i, j, l, rez;

	f >> m >> n;

	for(i=1; i<=m; i++)
		f >> a[i];

	for(i=1; i<=n; i++)
		f >> b[i];

	l = 1;
	rez = 0;

	for(i=1; i <= m && l <= n; i++)
	{
		for(j=l; j <= n; j++)
		{
			if(a[i] == b[j])
			{
				rez++;
				c[rez] = a[i];

				l = j;

				break;
			}
		}
	}

	g << rez << endl;

	for(i=1; i<=rez; i++)
		g << c[i] << ' ';

	f.close();
	g.close();
	return 0;
}