
#include<iostream>
#include<fstream>
using namespace std;

int n, m, a[1024], b[1024],k,sir[1024];
int L[1024][1024];


int max(int a, int b) {
	return (a > b) ? a : b;
}

int cate(int L[][1024], int i, int m, int val) {
	int count = 0;
	for (int j = 0; j <= m; j++)
		if (L[i][j] == val) count += 1;
	return count;
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

	int lung = lcs(n, m, a, b);



	g << lung<<"\n";	

	while (n && m) {
		if (L[n][m] == L[n][m - 1]) {
			m--;
		}
		else if (L[n][m] == L[n - 1][m]) {
			n--;
		}
		else {
			sir[k++] = a[n-1];
			m--; n--;
		}
	}
	


	for (int i = k-1; i >=0; i--) {
		g << sir[i] << " ";
	}


	return 0;
}
