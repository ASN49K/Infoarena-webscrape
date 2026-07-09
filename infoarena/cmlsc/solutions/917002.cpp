#include <fstream>
#include <algorithm>
using namespace std;

short a[1027], b[1027], m, n, D[1027][1027], v[1027], val;

ofstream fout ("cmlsc.out");

int main ()
{
	ifstream fin ("cmlsc.in");
	fin >> m >> n;
	for (int i = 1; i <= m; ++i)
		fin >> a[i];
	for (int i = 1; i <= n; ++i)
		fin >> b[i];
	fin.close();
	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
			if (a[i] == b[j])
				D[i][j] = D[i-1][j-1] + 1;
			else
				D[i][j] = max (D[i-1][j], D[i][j-1]);
	}
	fout << D[m][n] << "\n";
	for (int i = m, j = n; i && j;)
		if (a[i] == b[j])
			v[val++] = a[i], --j, --i;
		else
			if (D[i][j-1] < D[i-1][j])
				--i;
		else
			--j;
	for (int i = val - 1; i >= 0; --i)
		fout << v[i] << " ";
	fout.close();
	return 0;
}
	
