#include <stdio.h>
FILE *f=fopen("euclid2.in","r"),*g=fopen("euclid2.out","w");
int t,i,a,b,d;
int main(void)
{
	fscanf(f,"%d",&t);
	for (i=1;i<=t;i++)
	{
		fscanf(f,"%d%d",&a,&b);
		if (a<b)
		{
			d=a;
			a=b;
			b=d;
		}
		d=a%b;
		while (d!=0)
		{
			a=b;
			b=d;
			d=a%b;
		}
		fprintf(g,"%d\n",b);
	}
	fclose(g);
	return 0;
}