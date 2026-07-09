#include <iostream>
#include <cstdlib>
#include <fstream>

#define max(a,b) ((a)>(b)?(a):(b))
#define Nmax 1024
#define Mmax 1024

std::ofstream out;

int D[Nmax][Mmax], a[Nmax], b[Mmax];

void read(int *n, int *m)
{
	// read n and m
	std::ifstream in;
	in.open ("cmlsc.in");
	in >> *n >> *m;

	for (int i = 0; i < *n; ++i) {
		in >> a[i];	
	}

	for (int i = 0; i < *m; ++i) {
		in >> b[i];
	}
}

void print_reverse (int n, int m)
{
	if (n < 0 || m < 0) {
		return;
	}
	if (a[n] == b[m]) {
		print_reverse((n - 1), (m - 1));
		out << a[n] << " ";
		return;
	}

	if (D[n - 1][m] > D[n][m - 1]) {
		print_reverse((n - 1), m);
		return;
	}

	print_reverse(n, (m-1));
	return;
}

int cmlsc (int n, int m)
{
	out.open("cmlsc.out");
	
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[0]) {
			D[i][0] = 1;
		}
		else {
			D[i][0] = 0;
		}
	}

	for (int j = 0; j < n; ++j) {
		if (a[0] == b[j]) {
			D[0][j] = 1;
		}
		else {
			D[0][j] = 0;
		}
	}


	for (int i = 1; i < n; ++ i) {
		for (int j = 1; j < m; ++j) {
			if (a[i] == b[j]) {
				D[i][j] = D[i-1][j-1] + 1;
			} else {
				D[i][j] = max(D[i][j-1], D[i-1][j]);
			}
		}
	}

	out << D[n-1][m-1] << std::endl;
	print_reverse(n - 1, m - 1);
}

int main()
{
	int n, m;

	read (&n, &m);
	cmlsc (n, m);

	return 0;
}
