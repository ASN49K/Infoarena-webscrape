#include <fstream>
#include <vector>
#include <iomanip>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int an, bn;
int a[10040], b[10040], afisare[10024], len;
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

	for (int i = an, j = bn;;) {
		if (m[i - 1][j - 1] == m[i][j] - 1) {
			afisare[len++] = a[i--];
			j--;
		}
		else {
			i--;
		}
		if (!m[i][j]) {
			break;
		}
	}
	fout << len << '\n';
	for (int i = len-1; i >= 0; i--) {
		fout << afisare[i] << ' ';
	}

	return 0;
}