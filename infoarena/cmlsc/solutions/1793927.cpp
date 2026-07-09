#include<fstream>

using namespace std;

int main()
{
	ifstream in("cmlsc.in");
	ofstream out("cmlsc.out");

	int m, n, a[1024], b[1024], c[1024], k = 0;
	in >> m >> n;
	for (int i = 0; i < m; i++)
		in >> a[i];
	for (int i = 0; i < n; i++)
		in >> b[i];

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i] == b[j])
			{
				c[k] = a[i];
				k++;
			}
		}
	}

	out << k << "\n";
	for (int i = 0; i < k; i++)
		out << c[i] << " ";

	return 0;
}