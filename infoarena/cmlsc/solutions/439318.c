#include <stdio.h>
#include <stdlib.h>

#define NMAX 1024

int main()
{
	int s[NMAX], p[NMAX], i, j;
	int l = 0,  v[NMAX];
	int a[NMAX][NMAX];
	char b[NMAX][NMAX];
	FILE *f = fopen("cmlsc.in" , "rt");
	FILE *g = fopen("cmlsc.out" , "wt");
	fscanf(f, "%d" , &s[0]);
	fscanf(f, "%d" , &p[0]);
	for(i = 1; i <= s[0]; i++) {
		fscanf(f,"%d", &s[i]);
	}
	for(i = 1; i <= p[0]; i++) {
		fscanf(f, "%d" , &p[i]);
	}
	for(i = 0; i <= s[0]; i++)
		a[i][0] = 0;
	for(j = 0; j <= p[0]; j++)
		a[0][j] = 0;
	for(i = 1; i <= s[0]; i++)
		for (j = 1; j <= p[0]; j++) {
			if(s[i] == p[j]) {
	       			a[i][j] = a[i-1][j-1] + 1;
				b[i][j] = 'd';
			}
			else {
				if(a[i][j-1] > a[i-1][j])
				{
					a[i][j] = a[i][j-1];
					b[i][j] = 'l';
				}
				else {
					a[i][j] = a[i-1][j];	
					b[i][j] = 'u';
				}	
			}
		}
	fprintf(g, "%d\n" , a[s[0]][p[0]]);
	for(i = s[0], j = p[0]; i > 0, j > 0;) {
		if(b[i][j] == 'u')
			i--;
		if(b[i][j] == 'l')
			j--;
		if(b[i][j] == 'd') {
			v[++l] = s[i];
			i--;
			j--;
		}
	}
	for(i = l; i >= 1; i--) {
		fprintf(g, "%d " , v[i]);
	}
	fclose(f);
	fclose(g);
	return 0;
}


