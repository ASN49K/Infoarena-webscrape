#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
	if(a<b)
		return b;

	return a;
}


int main()
{
	int numar_perechi;
	int a,b;

	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");

	int cmmdc;
	int null;
	null=fscanf(f,"%d",&numar_perechi);	
	for(int i=0;i<numar_perechi;i++)
	{
		cmmdc=1;
		null=fscanf(f,"%d%d",&a,&b);

		for(int j=max(a,b)/2;j>=2;j--)
				if(a%j==0 && b%j==0)
				{
					cmmdc=j;
					break;
				}	

		fprintf(g,"%d\n",cmmdc);
	}

	null=max(null,null);	

	fclose(f);
	fclose(g);

	return 0;
}


