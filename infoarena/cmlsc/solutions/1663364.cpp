// http://www.infoarena.ro/problema/cmlsc
#include <fstream>
#define MAXLEN 1024

int M, N, P, a[MAXLEN], b[MAXLEN], c[MAXLEN][MAXLEN], seq[MAXLEN];

using namespace std;

int main() {
	ifstream fin("cmlsc.in");
	ofstream fout("cmlsc.out");
	fin >> M >> N;
	for (int i = 0; i < M; i++)
		fin >> a[i];
	for (int j = 0; j < N; j++)
		fin >> b[j];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			if (a[i] == b[j])
				c[i][j] = 1 + c[i - 1][j - 1];
			else
				c[i][j] = (c[i - 1][j] > c[i][j - 1]) ? c[i - 1][j] : c[i][j - 1];
		}
	for (int i = M, j = N; i, j;) {
		if (a[i] == b[j])
			seq[P++] = a[i], i--, j--;
		else if (c[i - 1][j] < c[i][j - 1])
			j--;
		else
			i--;
	}
	fout << P << endl;
	for (int k = P; k; k--)
		fout << seq[k] << " ";
	return 0;
}