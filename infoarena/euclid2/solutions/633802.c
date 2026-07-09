// Algoritmul lui Euclid

#include <stdio.h>

int euclid(long a, long b)
{
	if(!b)
		return a;
	else
		euclid(b,b%a);
}

int main()
{
	int n,i;
	long a,b;
	FILE* f=fopen("euclid2.in","rt");
	FILE* g=fopen("euclid2.out","wt");

	fscanf(f,"%d", &n);
	
	for (i=1;i<=n;i++)
	{
		fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}

	fclose(f);
	fclose(g);

	return 0;
}