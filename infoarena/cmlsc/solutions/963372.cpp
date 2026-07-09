#include <fstream>
#include <iostream>
using namespace std;

const int MAX_N = 1100;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[MAX_N], b[MAX_N];
int N, M;

int d[MAX_N][MAX_N];
int result;
int cmlsc[MAX_N];

void read_input();
void solve();
void print_output();


int main() {
	read_input();
	solve();
	print_output();
	return 0;
}

void read_input() {
	fin >> N >> M;
	for (int i = 1; i <= N; ++i) {
		fin >> a[i];
	}

	for (int i = 1; i <= M; ++i) {
		fin >> b[i];
	}
}

void solve() {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			if (a[i] == b[j]) {
				d[i][j] = d[i - 1][j - 1] + 1;
			} else {
				d[i][j] = max(d[i - 1][j], d[i][j - 1]);
			}
		}
	}
	
	result = 0;
	int i = N, j = M;
	while (i && j) {
		if (a[i] == b[j]) {
			cmlsc[++result] = a[i];
			--i, --j;
		} else if (d[i - 1][j] > d[i][j - 1]) {
			--i;
		} else {
			--j;
		}
	}
}

void print_output() {
	fout << result << '\n';
	for (int i = result; i > 0; --i) {
		fout << cmlsc[i] << ' ';
	}
}
