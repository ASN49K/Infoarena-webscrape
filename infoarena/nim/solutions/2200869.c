#include<stdio.h>

#define NMAX 100006

int main()
{
	int t, i, j, n, s, x;
	FILE* in = NULL;
	FILE* out = NULL;
	in = fopen("nim.in", "rt");
	out = fopen("nim.out", "wt");
	fscanf(in, "%d", &t);
	for(i = 1; i <= t; i++){
		fscanf(in, "%d", &n);
		for(j = 1; j <= n; j++){
			fscanf(in, "%d", &x);
			if(j == 1) s = x;
			else s = s^x;
		}
		if(s != 0)
			fprintf(out, "DA\n");
		else fprintf(out, "NU\n");
	}
	fclose(in);
	fclose(out);
	return 0;
}
