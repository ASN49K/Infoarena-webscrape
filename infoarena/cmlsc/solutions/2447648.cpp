
#include<iostream>
#include<fstream>
using namespace std;

int n, m, a[1024], b[1024];
int L[1024][1024];


int max(int a, int b) {
	return (a > b) ? a : b;
}


int lcs(int n, int m, int a[], int b[]) {
	

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0)
				L[i][j] = 0;

			else if (a[i - 1] == b[j - 1])
				L[i][j] = L[i - 1][j - 1] + 1;
			else
				L[i][j] = max(L[i - 1][j], L[i][j - 1]);

		}
	}
	return L[n][m];
}




int main() {
	

	

	ifstream f("cmlsc.in");
	ofstream g("cmlsc.out");

	f >> n; f >> m;
	for (int i = 0; i < n; i++) {
		f >> a[i];
	}
	for (int i = 0; i < m; i++) {
		f >> b[i];
	}

	g << lcs(n, m, a, b)<<"\n";	
	while (n) {
		if (L[n][m] == L[n - 1][m]+1) {
			g << a[n-1] << " ";
		}
		n -= 1;
	}


	return 0;
}




