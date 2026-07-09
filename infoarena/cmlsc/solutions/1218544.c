#include <stdio.h>
#include <stdlib.h>

#define max(a , b) (a) > (b) ? (a) : (b)
#define min(a , b) (a) < (b) ? (a) : (b)

void * xmalloc(int mem) {
	void * ptr = NULL;

	ptr = malloc(mem);

	if (ptr == NULL) {
		fprintf(stderr, "Eroare la alocare");
		exit(EXIT_FAILURE);
	}

	return ptr;
}

int ** aloca_matrice(int n, int m) {
	int ** matrice;
	int i;

	matrice = (int**) xmalloc(n * sizeof(int*));

	for (i = 0; i < n; i++) {
		matrice[i] = (int*) xmalloc(m * sizeof(int));
	}

	return matrice;
}

void dealoca_matrice(int *** mat, int n) {
	int i;

	for (i = 0; i < n; i++) {
		free((*mat)[i]);
		(*mat)[i] = NULL;
	}

	free(*mat);
	(*mat) = NULL;
}

int main() {
	FILE *in = fopen("cmlsc.in", "r");
	FILE *out = fopen("cmlsc.out", "w");

	int n, m, i, j;
	int *a = NULL, *b = NULL;
	int **rez = NULL;
	int *vec = NULL;
	int nr = 0;

	fscanf(in, "%d%d", &n, &m);

	a = (int*) xmalloc((n + 1) * sizeof(int));
	b = (int*) xmalloc((m + 1) * sizeof(int));
	vec = (int*) xmalloc((min(n,m) + 1) * sizeof(int));

	for (i = 1; i <= n; i++) {
		fscanf(in, "%d", &a[i]);
	}

	for (i = 1; i <= m; i++) {
		fscanf(in, "%d", &b[i]);
	}

	rez = aloca_matrice(n + 1, m + 1);

	for(i = 0 ; i <= n ; i++)
	{
		rez[i][0] = 0;
	}

	for(i = 0 ; i <= m ; i++)
	{
		rez[0][i] = 0;
	}

	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				rez[i][j] = rez[i - 1][j - 1] + 1;
			} else {
				rez[i][j] = max(rez[i - 1][j], rez[i][j - 1]);
			}
		}
	}

	fprintf(out, "%d\n", rez[n][m]);

	i = n;
	j = m;

	while (i != 0 && j != 0) {
		if (a[i] == b[j]) {
			vec[nr++] = a[i];
			i--;
			j--;
		} else {
			if (rez[i - 1][j] < rez[i][j - 1]) {
				j--;
			} else {
				i--;
			}
		}
	}

	for (i = nr - 1; i >= 0; i--) {
		fprintf(out, "%d ", vec[i]);
	}



	free(a);
	a = NULL;
	free(b);
	b = NULL;
	free(vec);
	vec = NULL;

	dealoca_matrice(&rez, n + 1);

	fclose(in);
	fclose(out);

	return 0;
}
