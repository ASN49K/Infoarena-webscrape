// Algoritmul lui Euclid

#include <stdio.h>

int euclid(int a, int b)
{
	if(b==0)
		return a;
	else
		euclid(b,a%b);
}

int main()
{
	int n,i;
	int a,b;
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