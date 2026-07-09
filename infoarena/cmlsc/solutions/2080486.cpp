#include<iostream>
#include<fstream>
using namespace std;

short n, m, a[1025], b[1025], solution[1025];

short c[1025][1025];

int main() {
	ifstream inFile("cmlsc.in");
	ofstream outFile("cmlsc.out");

	inFile >> m >> n;
	for (int i = 1; i <= m; ++i) {
		inFile >> a[i];
	}
	for (int i = 1; i <= n; ++i) {
		inFile >> b[i];
	}
	for (int i = 0; i <= m; ++i) {
		c[i][0] = 0;
	}
	for (int i = 0; i <= n; ++i) {
		c[0][i] = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				c[i][j] = c[i - 1][j - 1] + 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
			}
			else {
				c[i][j] = c[i][j - 1];
			}
		}
	}

	int line = m, column = n, index = 0;

	while (line != 0 || column != 0) {
		if (a[line] == b[column]) {
			solution[index++] = a[line];
			--line;
			--column;
		}
		else if (c[line - 1][column] >= c[line][column - 1]) {
			--line;
		}
		else {
			--column;
		}
	}

	outFile << c[m][n] << "\n";
	for (int i = index - 1; i >= 0; --i) {
		outFile << solution[i] << "  ";
	}
	inFile.close();
	outFile.close();
	return 0;
}