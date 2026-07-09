#include <stdio.h>

int main() {
	FILE *in, *out;
	int i, j, n, m, v1[1024], v2[1024], km, its = 0;
	int i2, s[1024], c = 0;

	in = fopen("cmlsc.in", "rt");
	out = fopen("cmlsc.out", "wt");

	fscanf(in, "%d %d", &n, &m);
	
	for (i = 0; i < n; i++) {
		fscanf(in, "%d", &v1[i]);
	}
	
	for (i = 0; i < m; i++) {
		fscanf(in, "%d", &v2[i]);
	}
	
	km = 0;
	i2 = 0;
	
	for (i = 0; i < n; i++) {
		for (j = i2; j < m; j++) {
			if (v1[i] == v2[j]) {
				s[c] = v1[i];
				c++;
				i2 = j;
				break;
			}
		}
	}
	
	fprintf(out, "%d\n", c);
	
	for (i = 0; i < c; i++) {
		fprintf(out, "%d ", s[i]);
	}

}