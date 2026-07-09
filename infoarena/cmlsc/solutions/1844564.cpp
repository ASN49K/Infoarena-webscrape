#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");
	int i,j=1,cj,m, n, a[1030], b[1030];
	f >> m >> n;
	for (i = 1;i <= m;i++)
		f >> a[i];
	for (i = 1;i <= n;i++)
		f >> b[i];
	int k = 0;
	for (i = 1;i <= m;i++)
	{
		cj = j;
		for (;j <= n;j++)
		{
			if (a[i] == b[j])
			{
				k++;
				break;
			}
			if (j == n)
			{
				j = cj;
				break;
			}
		}
	}
	g << k << "\n";

	for (i = 1;i <= m;i++)
	{
		for (j = 1;j <= n;j++)
		{
			if (a[i] == b[j])
			{
				g << a[i] << " ";
			}
		}
	}

	g << "\n";
	f.close();;
	g.close();
	return 0;
}