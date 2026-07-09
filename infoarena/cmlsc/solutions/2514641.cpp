#include <fstream>

#define NMAX 1024

int main()
{
	std::ifstream fin("cmlsc.in");
	std::ofstream fout("cmlsc.out");
	
	int m, n;
	fin >> m >> n;
	int a[NMAX], b[NMAX], c[NMAX];

	for (int i = 0; i < m; i++)
		fin >> a[i];

	for (int i = 0; i < n; i++)
		fin >> b[i];

	int k = 0, ok = 0;
	for (int i = 0; i < m; i++) {
		int j = ok;
		while (j < n) {
			if (a[i] == b[j]) {
				c[k++] = a[i];
				ok = j + 1;
				break;
			}
			j++;
		}
	}

	fout << k << "\n";
	for (int i = 0; i < k; i++)
		fout << c[i] << " ";

	fin.close(), fout.close();

	return 0;
}