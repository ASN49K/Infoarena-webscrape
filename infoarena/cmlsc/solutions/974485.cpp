#include <fstream>
#include <iostream>
using namespace std;

#define NMax 1024
#define find_max(a,b) ((a > b) ? a : b)

int main()
{
	ifstream in("cmlsc.in"); ofstream out("cmlsc.out");
	int m, n, a[NMax], b[NMax], c[NMax], d[NMax][NMax], i, j;
	in >> m >> n;

	for (i = 1; i <= m; i++)
		in >> a[i];	
	for (i = 1; i <= n; i++)
		in >> b[i];
	
	for (i = 0; i <= m; i++)
		for (j = 0; j <= n; j++)
			if (!i || !j)
				d[i][j] = 0;
			else
				if (a[i] == b[j])
					d[i][j] = d[i-1][j-1] + 1;
			else
				d[i][j] = find_max(d[i-1][j],d[i][j-1]);

	int w = 0; i = m; j = n;
	while (i && j)
		if (a[i] == b[j])
		{
			w++;
			c[w] = a[i];
			i--; j--;
		}
		else
			if (d[i-1][j] < d[i][j-1])
				j--;
		else
			i--;
	
	out << w << "\n";
	for (i = w; i; i--)
		out << c[i] << " ";
}