#include <stdio.h>
#include<stdlib.h>

int main()
{
	FILE *f,*g;
	f=fopen("euclid2.in","r");
	if(!f)
	{
		fprintf(stderr,"Eroare la deschiderea fisierului\n");
		exit(EXIT_FAILURE);
	}
	g=fopen("euclid2.out","w");
	if(!g)
	{
		fprintf(stderr,"Eroare la deschiderea fisierului\n");
		exit(EXIT_FAILURE);
	}
	int n,a,b,c;
	fscanf(f,"%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		c=0;
		fscanf(f,"%d",&a);
		fscanf(f,"%d",&b);
		while(b)
		{
			c=a%b;
			a=b;
			b=c;
		}
		fprintf(g,"%d\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}
