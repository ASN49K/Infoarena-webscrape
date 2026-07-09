#include <iostream>
#include <fstream>

using namespace std;

short** mat;

int main() {
	ifstream input ("cmlsc.in");

	int n, m;
	input >> n >> m;
	short sor1[n];
	short sor2[m];
	mat = new short*[n + 1];

	for (int i = 0; i < n; i++) {
		mat[i] = new short[m + 1];
		input >> sor1[i];
	}

	mat[n] = new short[m + 1]; 

	for (int i = 0; i < m; i++) {
		input >> sor2[i];
	}

	int ay = 0, ax = 0, max = 0;

	for (int y = 1; y <= n; y++) {
		for (int x = 1; x <= m; x++) {
			mat[y][x] = mat[y][x - 1] > mat[y - 1][x] ? mat[y][x - 1] : mat[y - 1][x];
			if (sor1[y - 1] == sor2[x - 1]) {
				mat[y][x]++;
				if (mat[y][x] >= max) {
					max = mat[y][x];
					ay = y;
					ax = x;
				}
			}
		}
	}

	short res[max];
	int cdown = max, end = 0;
	int axm = ax;

	while (ay >= 1) {
		while (ax >= 1) {
			if (mat[ay][ax] == cdown && sor1[ay - 1] == sor2[ax - 1]) {
				res[end++] = sor1[ay - 1];
				cdown--;
				ax = axm;
				break;
			} else {
				ax--;
				if (ax == 0) {
					ax = axm;
					break;
				}
			}
		}
		ay--;
	}

	ofstream output ("cmlsc.out");
	output << max << "\n";
	for (int i = end - 1; i >= 0; i--) output << res[i] << " ";
	output << "\n";

	return 0;
}