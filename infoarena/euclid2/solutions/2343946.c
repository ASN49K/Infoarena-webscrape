#include <stdio.h>
#include <stdlib.h>

int main()
{
	int numar_perechi;
	int a,b;
	int *rezultate=calloc(1,sizeof(int));

	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");

	fscanf(f,"%d",&numar_perechi);



	for(int i=0;i<numar_perechi;i++)
	{
		fscanf(f,"%d %d\n",&a,&b);

		while(a!=b)
		{
			if(a>b)
				a=a-b;
			else
				b=b-a;
		}
		
		rezultate[i]=b;

		rezultate=realloc(rezultate,(i+2)*sizeof(int));
	}

	
	for(int i=0;i<numar_perechi;i++)
		fprintf(g,"%d\n",rezultate[i]);

	free(rezultate);

	fclose(f);
	fclose(g);

	return 0;
}


