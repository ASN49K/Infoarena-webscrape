#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a,int b)
{
	if(b==0)
		return a;
	return cmmdc(b,a%b);
}

int main()
{
	int numar_perechi;
	int a,b;

	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");

	int null;

	null=fscanf(f,"%d",&numar_perechi);	

	for(int i=0;i<numar_perechi;i++)
	{
		null=fscanf(f,"%d%d",&a,&b);
		fprintf(g,"%d\n",cmmdc(a,b));
	}

	null=cmmdc(null,null);	

	fclose(f);
	fclose(g);

	return 0;
}


