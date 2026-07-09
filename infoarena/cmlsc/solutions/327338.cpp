#include<stdio.h>
#define dim 1025
using namespace std;

int a[dim],b[dim],mat[dim][dim], s[dim],x,y;

int max(int x, int y)
{ if (x > y) return x;
  return y;
}


int main()
{ int n,m,i,j,k;

	FILE *f = fopen("cmlsc.in", "r");
	FILE *g = fopen("cmlsc.out", "w");
	
	fscanf(f, "%d%d", &n, &m );
	
	for (i = 1; i <= n; i++)
		fscanf(f, "%d", &a[i]);
	
	for(i = 1; i <= m; i++)
		fscanf(f, "%d", &b[i]);
	
	for (i = 1; i <= n; i++)
		for(j = 1; j <= m; j++)
			if(a[i] == b[j]) 
				mat[i][j] = mat[i-1][j-1] + 1;
			  else mat[i][j] = max( mat[i-1][j], mat[i][j-1]);
	
	i = n; j = m; k = 0;
	
	while( i != 0 )
		if(a[i] == b[j])
			s[++k] = a[i], i--, j--;
		  else if (mat[i][j-1] > mat[i-1][j]) j--;
			  else i--;
		  
	fprintf(g, "%d\n", k);
	for(i = k; i >= 1; i--)
		fprintf(g, "%d ", s[i]);
	
	fprintf(g, "\n");
	
	
	fclose(f);
	fclose(g);
	return 0;
}