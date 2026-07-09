
#include <stdio.h>

#define SIZE 1024

char t[SIZE + 1][SIZE + 1];
char a[SIZE + 1], b[SIZE + 1], s[SIZE + 1];
int n, m, l;

void dinamic() {
	int i, j;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) {
			if(a[i] == b[j])
				t[i][j] = t[i-1][j-1] + 1;
			else {
				if(t[i-1][j] > t[i][j-1]) t[i][j] = t[i-1][j];
				else t[i][j] = t[i][j-1];
			}
		}

	i = n; j = m; l = 0;
	while(i) {
		if(a[i] == b[j]) {
			s[++l] = a[i];
			i--; j--;
		}
		else if(t[i-1][j] < t[i][j-1])
			j--;
		else
			i--;
	}
}

void afisare() {
	FILE *f=fopen("cmlsc.out", "w");
	int i;
	fprintf(f, "%d\n", l);
	for(i=l; i>0; i--) {
		fprintf(f, "%d ", (int)s[i]+1);
	}
	fprintf(f, "\n");
	fclose(f);
}

int citire() {
	int i, c;
	FILE *f=fopen("cmlsc.in", "r");
	if(f == NULL) { fclose(f); printf("eroare la citire"); return -1;};
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	for(i=1; i<=n; i++) {
		fscanf(f, "%d", &c);
		a[i] = (char)(c - 1);
	}
	for(i=1; i<=m; i++) {
		fscanf(f, "%d", &c);
		b[i] = (char)(c - 1);
	}
	fclose(f);
	return 0;
}

int main(int argc, char **argv) {
	if(citire() < 0) return -1;
	dinamic();
	afisare();
	return 0;
}
