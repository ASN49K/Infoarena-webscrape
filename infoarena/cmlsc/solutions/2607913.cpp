#include <iostream>
#include <fstream>

#define NMAX 1025
#define max(a,b) (a>b)? a:b

typedef unsigned int uint;

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

uint mat[NMAX][NMAX];
uint n, m;
int a[NMAX], b[NMAX];

void read_vec(uint size,int* vec) {
	for (uint i = 1;i <= size;++i)
		fin >> vec[i];
}

void build_mat() {
	fin >> n >> m;
	read_vec(n, a);
	read_vec(m, b);
	for(uint i=1;i<=n;++i)
		for (uint j = 1;j <= m;++j) {
			if (a[i] == b[j])
				mat[i][j] = 1 + mat[i - 1][j - 1];
			else
				mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
		}
}

void print_solution() {
	int sol[NMAX];
	uint k = mat[n][m], i = n, j = m;
	fout << k << '\n';
	while (i > 0 && j>0) {
		if (a[i] == b[j])
			sol[k--] = a[i], --i, --j;
		else
			if (mat[i - 1][j] >= mat[i][j - 1])
				--i;
			else
				--j;
	}
	k = mat[n][m];
	for (uint i = 1;i <= k;++i)
		fout << sol[i] << ' ';
}

int main()
{
	build_mat();
	print_solution();

	return 0;
}