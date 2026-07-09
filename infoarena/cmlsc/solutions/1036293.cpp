#include<fstream>
using namespace std;
int main()
{
	fstream f("cmlsc.in", ios::in);
	fstream g("cmlsc.out", ios::out);
	int v[1024], a[1024], b[1024], i, n, m, j, k;
	f >> n >> m;
	for (i = 1; i <= n; i++)
		f >> a[i];
	for (i = 1; i <= m; i++)
		f >> b[i];
	k = 0;
	for (i = 1; i <= n;i++)
	for (j = 1; j <= m;j++)
	if (a[i] == b[j])
	{
		k = k + 1;
		v[k] = a[i];
	}
	g << k << endl;
	for (i = 1; i <= k; i++)
		g << v[i] << " ";

	return 0;
}

