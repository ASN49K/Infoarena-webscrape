#include <stdio.h>

int m, n, i, j;
int a[1025], b[1025], c[1025][1025], sol[1025];

void main(void)
{	
	FILE *in = fopen("cmlsc.in", "r");
	FILE *out = fopen("cmlsc.out", "w");
	fscanf(in, "%d %d", &m, &n);
	for(i = 1; i <= m; i++) fscanf(in, "%d", &a[i]);
	for(i = 1; i <= n; i++) fscanf(in, "%d", &b[i]);
	
	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			if(a[i] == b[j])
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = (c[i-1][j] <= c[i][j-1] ? c[i][j-1] : c[i-1][j]);
	
	fprintf(out, "%d\n", c[m][n]);
	sol[0] = c[m][n];
	
	for(i = m, j = n; j != 0 || i != 0; )
		if(a[i] == b[j])
		{			
			sol[ sol[0]-- ] = a[i];
			i--;
			j--;
		}
		else if(j > 0 && c[i][j-1] == c[i][j])
			j--;
		else
			i--;
			
		for(i = 1; i <= c[m][n]; i++)
			fprintf(out, "%d ", sol[i]);
	
	fclose(in);
	fclose(out);
}
