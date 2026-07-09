#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAX = 1024;
int a[MAX], b[MAX];
int res[MAX][MAX];
int str[MAX];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int m, n;
	
	fin >> m >> n;
	
	for (int i = 1; i <= m; i++) {
		fin >> a[i];		
	}
	
	for (int i = 1; i <= n; i++) {
		fin >> b[i];		
	}
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i] == b[j]) {
				res[i][j] = res[i - 1][j - 1] + 1;
			} else {
				res[i][j] = max(res[i][j - 1], res[i - 1][j]);
			}			
		}		
	}
	
	fout << res[m][n] << '\n';
		
	int i = m, j = n, c = 0;
	
	while (i) {
		if (a[i] == b[j]) {			
			str[c] = a[i];
			c++;
			i--;
			j--;
		} else if (res[i][j - 1] < res[i - 1][j]) {
			i--;
		} else {
			j--;
		}
	}
	
	for (int i = c - 1; i >= 0; i--) {
		fout << static_cast<int>(str[i]) << ' ';
	}
	
	fin.close();
	fout.close();
	return 0;
}
