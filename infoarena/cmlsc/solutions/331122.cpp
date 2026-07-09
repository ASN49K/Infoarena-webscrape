#include<stdio.h>

int m, n, i, j, k;
int *a, *b, **l, s[1024];

void cmlsc(){

	for(i=0; i<=m; i++)
		l[i][0] = 0;
		
	for(j=0; j<=n; j++)
		l[0][j] = 0;
		
	for(i=1; i<=m; i++)
		for(j=1; j<=n; j++)
			if(a[i] == b[j]) l[i][j] = 1 + l[i-1][j-1];
			else l[i][j] = (l[i][j-1] > l[i-1][j]) ? l[i][j-1]:l[i-1][j];

	for(i=m, j=n, k=0; i;)
		if(a[i] == b[j]){
			s[k++] = a[i];
			--i;
			--j;
		}
		else 
			if(l[i][j-1] > l[i-1][j]) --j;
			else --i;

}

int main()
{
	FILE *ofile,*ifile;
	
	ifile = fopen("cmlsc.in", "r");
	fscanf(ifile, "%i %i", &m, &n);

	a = new int[m+1];
	b = new int[n+1];
	l = new int* [m+1];
	for(i=0; i<=m; i++)
		l[i] = new int[n+1];

	for(i=0; i<m; i++)
		fscanf(ifile, "%i", &a[i]);
	for(i=0; i<n; i++)
		fscanf(ifile, "%i", &b[i]);
	
	fclose(ifile);	

	cmlsc();

	ofile = fopen("cmlsc.out", "w");

	fprintf(ofile,"%i\n",l[m][n]);

	for(i=k-1; i>=0; i--)
		fprintf(ofile,"%i ",s[i]);
	fprintf(ofile,"\n");

	fclose(ofile);

	return 0;
}

