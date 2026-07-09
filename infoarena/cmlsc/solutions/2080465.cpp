#include<iostream>
#include<fstream>
using namespace std;

int n, m, a[1025], b[1025], solution[1025];
const char UP = 'U';
const char LEFT = 'L';
const char DIAGONAL = 'D';
typedef struct { 
	int elem; 
	char fromDirection; 
} CmlscData;

CmlscData c[1025][1025];

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
		c[i][0].elem = 0;
	}
	for (int i = 0; i <= n; ++i) {
		c[0][i].elem = 0;
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				c[i][j].elem = c[i - 1][j - 1].elem + 1;
				c[i][j].fromDirection = DIAGONAL;
			}
			else if (c[i - 1][j].elem >= c[i][j - 1].elem) {
				c[i][j].elem = c[i - 1][j].elem;
				c[i][j].fromDirection = UP;
			}
			else {
				c[i][j].elem = c[i][j - 1].elem;
				c[i][j].fromDirection = LEFT;
			}
		}
	}

	int line = m, column = n, index = 0, MAX = c[m][n].elem;

	solution[index++] = c[m][n].elem;

	while (line != 0 || column != 0) {
		if (c[line][column].fromDirection == DIAGONAL) {
			solution[index++] = a[line];
			--line;
			--column;
		}
		else if (c[line][column].fromDirection == LEFT) {
			--column;
		}
		else {
			--line;
		}
	}

	outFile << MAX << "\n";
	for (int i = index-1; i > 0; --i) {
		outFile << solution[i] << "  ";
	}
	inFile.close();
	outFile.close();
	return 0;
}