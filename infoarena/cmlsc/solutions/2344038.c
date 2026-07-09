#include <stdio.h>
#include <stdlib.h>

typedef struct custom_hashtable{

	int exista;
	int pozitie;

}Hashtable;

int main()
{
	int lungime_subsir=0;
	int lungime_sir1,lungime_sir2;
	int pozitia_ultimului;
	int lungime_maxima=0;

	FILE *f=fopen("cmlsc.in","r");
	FILE *g=fopen("cmlsc.out","w");

	fscanf(f,"%d%d",&lungime_sir1,&lungime_sir2);
	
	Hashtable *my_hashtable=calloc(256,sizeof(Hashtable));

	int vector_solutie[lungime_sir2];
	int contor=0;

	int vector_final[lungime_sir2];

	int x;

	for(int i=0;i<lungime_sir1;i++)
	{
		fscanf(f,"%d",&x);
		my_hashtable[x].exista=1;
		my_hashtable[x].pozitie=i;
	}

	for(int i=0;i<lungime_sir2;i++)
	{
		fscanf(f,"%d",&x);

		if(my_hashtable[x].exista==1)
		{
			if(lungime_subsir==0)
			{
				lungime_subsir++;
				
				if(lungime_subsir>lungime_maxima)
				{
					vector_final[contor]=x;
					vector_solutie[contor]=x;
					contor++;
					lungime_maxima=lungime_subsir;
				}

				pozitia_ultimului=my_hashtable[x].pozitie;
		
			}
			else
			{
				if(pozitia_ultimului<my_hashtable[x].pozitie)
				{
					lungime_subsir++;
						
					vector_solutie[contor]=x;
					contor++;							
						
					if(lungime_subsir>lungime_maxima)
					{
						for(int i=0;i<lungime_subsir;i++)
							vector_final[i]=vector_solutie[i];

						lungime_maxima=lungime_subsir;
					}			
	
				}
				
				pozitia_ultimului=my_hashtable[x].pozitie;


			}

		}		

	}

	fprintf(g,"%d\n",lungime_maxima);	

	for(int i=0;i<lungime_maxima;i++)
	{
		if(i==lungime_maxima-1)
			fprintf(g,"%d\n",vector_final[i]);
		else
			fprintf(g,"%d ",vector_final[i]);		
	}

	free(my_hashtable);
	fclose(f);
	fclose(g);

	return 0;
}
