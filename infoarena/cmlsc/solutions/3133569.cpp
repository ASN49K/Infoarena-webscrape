#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int N_MAX = (1 << 10);
const int M_MAX = (1 << 10);
unsigned char a[N_MAX + 1], b[M_MAX + 1];
short sclm[N_MAX + 1][M_MAX + 1];

static inline short max(short a, short b) {
	return (a > b) ? a : b;
}

static inline short max(short a, short b, short c) {
	return max(max(a, b), c);
}

void path(short r, short c) {
	if(!sclm[r][c])
		return;

	if(sclm[r - 1][c] == sclm[r][c])
		path(r - 1, c);
	else if(sclm[r][c - 1] == sclm[r][c])
		path(r, c - 1);
	else{
		path(r - 1, c - 1);
		fout << (int) a[r] << ' ';
	}
}

int main() {
	short n, m, x;
	fin >> n >> m;
	for(int i = 1; i <= n; ++i){
		fin >> x;
		a[i] = x;
	}
	for(int i = 1; i <= m; ++i){
		fin >> x;
		b[i] = x;
	}

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			sclm[i][j] = max(sclm[i][j - 1], sclm[i - 1][j], sclm[i - 1][j - 1] + (a[i] == b[j]));

	fout << sclm[n][m] << '\n';

	path(n, m);

	fout.put('\n');

	fin.close();
	fout.close();
	return 0;
}