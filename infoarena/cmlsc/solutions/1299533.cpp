#include<fstream>

using namespace std;

int n, m, i, j, k, nr, a[1050], b[1050], s[1050];

int main()
{
	ifstream f("cmlsc.in");
	ofstream h("cmlsc.out");
	f >> m >> n;
	for (i = 1; i <= m; ++i)
		f >> a[i];
	for (j = 1; j <= n; ++j)
		f >> b[j];
	i = 1; 
	nr = 0;
	j = 1;
	k = 1;
	while (i <= m)
	{
		while (k <= n && a[i] != b[k])
			++k;
		if (a[i] == b[k])
		{
			++nr;
			s[nr] = a[i];
			++i;
			++k;
			j = k;
		}
		else
		{
			++i;
			k = j;
		}
	}
	h << nr << '\n';
	for (i = 1; i <= nr; ++i)
		h << s[i] << " ";
	h << '\n';
}
