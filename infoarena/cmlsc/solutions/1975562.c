/* D[i][j] = lungimea celui mai lung subsir comun daca am alege elementul i din a, respectiv elementul j din b
 */

#include <stdio.h>
#include <stdlib.h>

#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define MAXN 1025

FILE *in, *out;

int n, m;
int a[MAXN], b[MAXN];
int D[MAXN][MAXN];

int max(int x, int y){
	if (x > y)
		return x;
	return y;
}

void afisareSolutie(void){

	int i, j, sol[MAXN], len = 0;

	for (i = n, j = m; i >= 1 && j >= 1; ){
		if (a[i] == b[j]){
			sol[len++] = a[i];
			--i, --j;
		}
		else{
			if (D[i - 1][j] > D[i][j - 1])
				--i;
			else
				--j;
		}
	}

	for (i = len - 1; i >= 0; --i)
		fprintf(out, "%d ", sol[i]);
	fprintf(out, "\n");
}

void algoritm(void){

	int i, j;

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= m; ++j)
			if (a[i] == b[j])
				D[i][j] = D[i - 1][j - 1] + 1;
			else
				D[i][j] = max(D[i - 1][j], D[i][j - 1]);

	fprintf(out, "%d\n", D[n][m]);

	afisareSolutie();
}


int main(void){

	int i;

	in = fopen(IN, "r");

	fscanf(in, "%d%d", &n, &m);
	for (i = 1; i <= n; ++i)
		fscanf (in, "%d", &a[i]);
	for (i = 1; i <= m; ++i)
		fscanf (in, "%d", &b[i]);

	fclose(in);

	out = fopen(OUT, "w");

	algoritm();

	fclose(out);

	return 0;
}