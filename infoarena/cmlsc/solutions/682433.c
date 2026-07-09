#include<stdio.h>
#include<stdlib.h>

#define N 256
#define MIN(a, b) (((a)<(b))?(a):(b))


void cpy(char *a, char *b, int n) {
	int i;
	for(i = 1; i <= n; ++i) {
		b[i] = a[i];
	}
}

int main() {
	
	int i, j, k;
	char *v;
	char *temp;
	char *final;
	int aux[N] = {0};
	int maxt = 0;
	int maxf = 0;
	int n, m;
	int x;

	FILE *f;
	f = fopen("cmlsc.in", "r");

	fscanf(f, "%d%d", &n, &m);

	v = (char*)malloc(m + 2);
	temp = (char*)malloc(MIN(n, m));
	final = (char*)malloc(MIN(n,m));

	for(i = 1; i <= n; ++i) {
		fscanf(f, "%d", &x);
		aux[x] = i;
	}

	for(i = 1; i <= m; ++i) {
		fscanf(f, "%d", &v[i]);
	}

	int last;
	for(i = 1; i <= m; ++i) {
		last = aux[v[i]];
		maxt = 1;
		k = 1;
		temp[k++] = v[i];
		for(j = i; j <= m; ++j) {
			if(aux[v[j]] > last) {
				last = aux[v[j]];
				++maxt;
				temp[k++] = v[j];
			}
		}
		if(maxt > maxf) {
			maxf = maxt;
			cpy(temp, final, maxf);
		}
	}

	fclose(f);

	f = fopen("cmlsc.out", "w");

	fprintf(f, "%d\n", maxf);
	for(i = 1; i <= maxf; ++i) {
		fprintf(f, "%d ", final[i]);
	}
	fprintf(f, "\n");

	return 0;
}
