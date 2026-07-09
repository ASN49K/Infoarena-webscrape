#include <stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
long a,b,n,i,r;
int main()
{
	fscanf(f,"%ld",&n);
	for (i=1;i<=n;i++)
	{
		fscanf (f,"%ld%ld",&a,&b);
		r=1;
		while (r!=0)
		{
			r=a%b;
			a=b;
			b=r;
		}
		fprintf(g,"%ld\n",a);
	}
	fclose(f);
	return 0;
}
