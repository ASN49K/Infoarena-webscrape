#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

FILE* ip;
FILE* op;

/*
 * c[i][j] = lungimea cmlsc al subsirurilor Xi si Yj
 */
int c[1024][1024];

/*
 * Folosit pentru afisarea cmlsc
 * b[i][j] = 0 => se afiseaza x[i] si se merge in diagonala in matricea c
 * b[i][j] = 1 => se merge in sus in matricea c (cmlsc al subsirurilor Xi-1 si Yj)
 * b[i][j] = 2 => se merge in stanga in matricea c (cmlsc al subsirurilor Xi si Yj-1)
 */
int b[1024][1024];

void afiseaza_cmlsc(int n, int m, int x[]) {

	if (n == 0 || m == 0) {

		return;
	}

	if (b[n][m] == 0) {

		afiseaza_cmlsc(n-1, m-1, x);

		fprintf(op, "%d ", x[n]);
	}

	else if (b[n][m] == 1) {

		afiseaza_cmlsc(n - 1, m, x);
	}

	else {

		afiseaza_cmlsc(n, m - 1, x);
	}
}

void cmlsc(int n, int m, int x[], int y[]) {

	/*
	 * Prima coloana contine doar elemente egale cu 0 
	 * c[i][0] = lumgimea cmlsc al sirurilor Xi si Y0 (Y0 = sir vid)
	 */
	for (int i = 0; i <= n; i++) {

		c[i][0] = 0;
	}

	/*
	 * Prima linie contine doar elemente egale cu 0
	 * c[0][j] = lungimea cmlsc al sirurilor X0 si Yj (X0 = sir vid)
	 */
	for (int i = 0; i <= m; i++) {

		c[0][i] = 0;
	}

	for (int i = 1; i <= n; i++) {

		for (int j = 1; j <= m; j++) {

			/*
			 * lungimea cmlsc(Xi, Yj) = 1 + cmlsc(Xi-1, Yj-1)
			 */
			if (x[i] == y[j]) {

				c[i][j] = 1 + c[i - 1][j - 1];
				b[i][j] = 0;
			}

			/*
			 * lungimea cmlsc(Xi, Yj) = max(cmlsc(Xi-1,Yj), cmlsc(Xi, Yj-1))
			 */
			else if (c[i - 1][j] >= c[i][j - 1]) {

				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}

			else {

				c[i][j] = c[i][j - 1];
				b[i][j] = 2;
			}
		}
	}

	fprintf(op, "%d\n", c[n][m]);

	afiseaza_cmlsc(n, m, x);
}

int main() {

	ip = fopen("cmlsc.in", "r");
	if (ip == NULL) {

		perror("Could not open input file");
		return 1;
	}

	op = fopen("cmlsc.out", "w");
	if (op == NULL) {

		perror("Could not open output file");
		return 1;
	}

	int n = -1, m = -1;
	int a[1024], b[1024];

	fscanf(ip, "%d", &n);
	fscanf(ip, "%d", &m);

	for (int i = 1; i <= n; i++) {

		fscanf(ip, "%d", &a[i]);
	}

	for (int i = 1; i <= m; i++) {

		fscanf(ip, "%d", &b[i]);
	}

	cmlsc(n, m, a, b);

	fclose(ip);
	fclose(op);

	return 0;
}