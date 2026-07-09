#include<stdio.h>

int n,m,v[257], max, i, crt, nr;

int main()
{
	FILE *f;
	f=fopen("cmlsc.in", "r");
	fscanf(f, "%d%d", &n, &m);

	for(i=0; i<n; i++)
	{
		fscanf(f, "%d", &crt);
		v[crt]++;
		if(crt>max)
			max=crt;
	}
	for(i=0; i<m; i++)
	{
		fscanf(f, "%d", &crt);
		v[crt]++;
		nr += v[crt] > 1 ? 1:0;
		if(crt>max)
			max=crt;
	}
	fclose(f);
	f=fopen("cmlsc.out", "w");
	fprintf(f, "%d\n", nr);
	for(i=0;i<=max; i++)
	{
		if(v[i] > 1)
			fprintf(f, "%d ",i);
	}

	
	return 0;
}