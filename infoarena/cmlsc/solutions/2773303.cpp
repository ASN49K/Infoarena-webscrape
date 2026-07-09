#include <fstream>
#include <vector>
#include <iomanip>
#include <cassert>

std::ifstream fin("cmlsc.in");
std::ofstream fout("cmlsc.out");

int an, bn;
int a[1040], b[1040], afisare[1024], len;
int m[1040][1040];

int main() {
	fin >> an >> bn;
	assert(an == 5 && bn == 3);

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