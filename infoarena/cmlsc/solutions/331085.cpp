#include<stdio.h>

int m, n, max, i, j, k;
unsigned char *a, *b, **l, s[1024];

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

	max=0;
	k=0;
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			if(l[i][j] > max){
				s[k++]=a[i];
				max = l[i][j];
			}
}

int main()
{
	FILE *ofile,*ifile;
	
	ifile = fopen("cmlsc.in", "r");
	fscanf(ifile, "%i %i", &m, &n);

	a = new unsigned char[m];
	b = new unsigned char[n];
	l = new unsigned char * [m];
	for(i=0; i<m; i++)
		l[i] = new unsigned char[n];

	for(i=0; i<m; i++)
		fscanf(ifile, "%i", &a[i]);
	for(i=0; i<n; i++)
		fscanf(ifile, "%i", &b[i]);
	
	fclose(ifile);	

	cmlsc();

	ofile = fopen("cmlsc.out", "w");

	for(i=0; i<m; i++){
		for(j=0; j<n; j++)
			fprintf(ofile,"%i ",l[i][j]);
		fprintf(ofile,"\n");
	}

	for(i=0; i<k; i++)
		fprintf(ofile,"%i ",s[i]);

	fclose(ofile);

	return 0;
}

