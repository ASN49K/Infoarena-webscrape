#include <stdio.h>

#define MAXSIZE 1025
#define SUS 1 
#define PRINT 2
#define STANGA 3
#define MAX(a, b) (a < b ? b : a)

int X[MAXSIZE], Y[MAXSIZE], D[MAXSIZE][MAXSIZE], rezultat[MAXSIZE];

int main()
{
	freopen("cmlsc.in", "rt", stdin);
	freopen("cmlsc.out", "wt", stdout);
	int m, n, i, j;
	scanf("%i%i", &m, &n);

	for (i = 1; i <= m; i++) {
		scanf("%i", &X[i]);
	}
	
	for (i = 1; i <= n; i++) {
		scanf("%i", &Y[i]);
	}

	// Rezolvare
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= n; j++) {
			if (X[i] == Y[j])
				D[i][j] = D[i - 1][j - 1] + 1; 
			else
				D[i][j] = MAX(D[i - 1][j], D[i][j - 1]); 
		}
	}

	int solutie[MAX(m, n)];
	int it = 0;

	// Print Solutie
	printf("%i\n", D[m][n]);

	for (i = m, j = n; i > 0 && j > 0;) {
		if (X[i] == Y[j]) {
			solutie[it++] = X[i];
			i--;
			j--;
		} else if (D[i - 1][j] < D[i][j - 1]){
			j--;
		} else {
			i--;
		}
	}

	for (it--; it >= 0; it--)
		printf("%i ", solutie[it]);
	
	return 0;
}
