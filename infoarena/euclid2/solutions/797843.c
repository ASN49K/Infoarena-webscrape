#include <stdio.h>

int euclid(int a, int b)
{
	if (b==0) return a;
	return euclid(b, a % b);
}

void main()
{
	int n,a,b,i;
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");

	fscanf(f,"%d",&n);

	for (i=0;i<n;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",euclid(a,b));
	}

	fclose(f);
	fclose(g);
}