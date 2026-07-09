#include <stdio.h>

int max(int x, int y) {
	if (x>y)
		return x;
	else
		return y;
}

int main() {
	// open files
	FILE *fin = fopen("cmlsc.in","r");
	FILE *fout = fopen("cmlsc.out","w");
	
	// reading input
	int n,m;
	fscanf(fin,"%d %d",&n,&m);
	
	int a[n+1];
	int b[m+1];
	for (int i=0; i<n; i++)
		fscanf(fin,"%d",&a[i+1]);
	for (int i=0; i<m; i++)
		fscanf(fin,"%d",&b[i+1]);
	
	

	// initiating
	int c[n+1][m+1];
	for (int i=0; i<n+1; i++)
		c[i][0] = 0;
	for (int i=0; i<m+1; i++)
		c[0][i] = 0;
		
	// computing substring length
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (a[i]==b[j])
				c[i][j] = c[i-1][j-1] + 1;
			else
				c[i][j] = max(c[i][j-1],c[i-1][j]);
		
	// computing substring
	int x = n;
	int y = m;
	int k = c[n][m];
	int d[k+1];
	
	while (k) {
		while (c[x][y-1] == c[x][y])
			y--;
		while (c[x-1][y] == c[x][y])
			x--;
		
		//printf("k=%d , x=%d , a[x]=%d\n",k,x,a[x]);
		d[k] = a[x];
		k--;
		x--;
		y--;
	}
	
	/*
	for (int i=1; i<=n;i++) {
		for (int j=1; j<=m; j++)
			printf("%3d",c[i][j]);
		printf("\n");
	}
	*/
		
	// print		
	fprintf(fout,"%d\n",c[n][m]);
	for (int i=1; i<=c[n][m]; i++)
		fprintf(fout,"%d ",d[i]);
		
	fclose(fin);
	fclose(fout);
	return 0;
}
