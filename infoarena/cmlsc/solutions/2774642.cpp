#include <fstream>
#include <vector>
#include <iomanip>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int an, bn;
int a[10040], b[10040], afisare[10024];
int m[10040][10040];

int main() {
	fin >> an >> bn;

	for (int i = 1; i <= an; i++) {
		fin >> a[i];
	}
	for (int i = 1; i <= bn; i++) {
		fin >> b[i];
	}
		
	for (int i = 1; i <= an; i++) {
		for (int j = 1; j <= bn; j++) {
			if (a[i] != b[j]) {
				m[i][j] = std::max(m[i - 1][j], m[i][j - 1]);
			}
			else {
				m[i][j] = m[i - 1][j - 1] + 1;
			}
		}
	}

	int max = m[an][bn];
	for (int i = an, j = bn; max;)
	{
		if (m[i - 1][j] == max) {
			i--;
			continue;
		}
		if (m[i][j - 1] == max) {
			j--;
			continue;
		}
		afisare[max] = a[i];
		i--;
		j--;
		max--;
	}

	fout << m[an][bn] << '\n';
	for (int i = 1; i <= m[an][bn]; i++) {
		fout << afisare[i] << ' ';
	}

	return 0;
}