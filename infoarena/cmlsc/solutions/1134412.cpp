#include<fstream>
using namespace std;
int main()
{
	int n, k, a[100], b[100], c[100], i, j, d = 0;
	ifstream g("cmlsc.in");
	ofstream f("cmlsc.out");
	g >> n >> k;

	for (i = 0; i < n; i++)
		g >> a[i];
	for (i = 0; i < k; i++)
		g >> b[i];
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < k; j++)
		if (a[i] == b[j])
		{
			c[d] = a[i];
			d++;
		}
	}
	f << d;
	f << endl;
	for (i = 0; i < d; i++)
		f << c[i] << " ";
}