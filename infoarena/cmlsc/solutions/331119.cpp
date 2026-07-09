#include<stdio.h>

int m, n, max, i, j, k;
int a[1024], b[1024], l[1024][1024], s[1024];

void cmlsc(){

	max=0;
	for(i=0; i<m; i++){
		if(a[i] == b[0]) max=1;
		l[i][0] = max;
	}

	max=0;
	for(i=0; i<n; i++){
		if(a[0] == b[i]) max=1;
		l[0][i] = max;
	}

	for(i=1; i<m; i++)
		for(j=1; j<n; j++)
			if(a[i] == b[j]) l[i][j] = 1 + l[i-1][j-1];
			else l[i][j] = (l[i][j-1] > l[i-1][j]) ? l[i][j-1]:l[i-1][j];

	for(i=m-1, j=n-1, k=0; i>=1;)
		if(a[i] == b[j]){
			s[k++] = a[i];
			--i;
			--j;
		}
		else 
			if(l[i][j-1] > l[i-1][j]) --j;
			else --i;
	if(a[0] == b[j])
		s[k++] = a[0];

}

int main()
{
	FILE *ofile,*ifile;
	
	ifile = fopen("cmlsc.in", "r");
	fscanf(ifile, "%i %i", &m, &n);

	/*
	a = new int[m];
	b = new int[n];
	l = new int* [m];
	*/
	for(i=0; i<m; i++)
		l[i] = new int[n];

	for(i=0; i<m; i++)
		fscanf(ifile, "%i", &a[i]);
	for(i=0; i<n; i++)
		fscanf(ifile, "%i", &b[i]);
	
	fclose(ifile);	

	cmlsc();

	ofile = fopen("cmlsc.out", "w");

	fprintf(ofile,"%i\n",l[m-1][n-1]);

	for(i=k-1; i>=0; i--)
		fprintf(ofile,"%i ",s[i]);
	fprintf(ofile,"\n");

	fclose(ofile);

	return 0;
}

