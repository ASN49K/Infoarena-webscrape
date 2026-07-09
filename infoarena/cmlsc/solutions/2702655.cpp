#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <queue>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1024], b[1024], d[1024][1024], ras[1024];

int bst = 0;

int main() {
	int ans = 0, k = 0;
	fin >> n >> m;
	for (int i = 1; i <= n; ++i)
		fin >> a[i];
	for (int i = 1; i <= m; ++i)
		fin >> b[i];

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i] == b[j])
				d[i][j] = 1 + d[i - 1][j - 1];					////consideri ca nu ai mai cuplat a i - a litera din primul sir cu altceva, analog a j-a cifra din al doilea sir
			else
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);


	int i = n, j = m;
	while (i > 0) {
		if (a[i] == b[j])
			ras[++bst] = a[i], --i, --j;																	////                          Y   X	
		else if (d[i - 1][j] < d[i][j - 1])																	////                 [][][][][][///]          scazi din j deoarece vrei X cu X
			--j;																							///                  [][][][///]
		else																								///                       X  Z
			--i;
	}

	fout << bst << "\n";

	for (i = bst; i; --i)
		fout << ras[i] << " ";

	return 0;
}