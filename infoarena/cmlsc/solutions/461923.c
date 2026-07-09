
#include <stdio.h>

#define SIZE 1024

int path[SIZE + 1][SIZE + 1][2];
char t[SIZE + 1][SIZE + 1];
char a[SIZE + 1], b[SIZE + 1], s[SIZE + 1];
int n, m;
int px, py, l;

void dinamic() {
	int i, j, max, x, y;
	int *p;
	for(i=1; i<=n; i++)
		for(j=1; j<=m; j++) {
			p = path[i][j];
			p[0] = i-1; p[1] = j-1;
			max = t[i-1][j-1];
			if(t[i-1][j] > max) { max = t[i-1][j]; p[1]++;}
			if(t[i][j-1] > max) { max = t[i][j-1]; p[0]++;}
			if(a[i] == b[j]) {
				t[i][j] = max + 1;
				px = i; py = j; l = t[i][j];
			}
			else
				t[i][j] = max;
		}
	x=px;y=py;j=l;
	while(t[x][y] != 0) {
		if(t[px][py] != t[x][y]) {
			s[j--] = a[x];
		}
		x = px; y = py;
		px = path[x][y][0];
		py = path[x][y][1];
	}
}

void afisare() {
	FILE *f=fopen("cmlsc.out", "w");
	int i;
	fprintf(f, "%d\n", l);
	for(i=1; i<=l; i++) {
		fprintf(f, "%d ", (int)s[i]);
	}
	fprintf(f, "\n");
	fclose(f);
}

int citire() {
	int i, c;
	FILE *f=fopen("cmlsc.in", "r");
	if(f == NULL) { fclose(f); f=fopen("cmlsc.out", "w"); fprintf(f, "eroare la citire"); fclose(f); return -1;};
	fscanf(f, "%d", &n);
	fscanf(f, "%d", &m);
	for(i=1; i<=n; i++) {
		fscanf(f, "%d", &c);
		a[i] = (char)c;
	}
	for(i=1; i<=m; i++) {
		fscanf(f, "%d", &c);
		b[i] = (char)c;
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
