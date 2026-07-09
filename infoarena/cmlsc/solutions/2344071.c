#include <stdio.h>
#include <stdlib.h>

typedef struct my_hash{

	int exista;
	int pozitie;

}Hash;

int main()
{

	int lungime_sir1,lungime_sir2;

	FILE *f=fopen("cmlsc.in","r");
	FILE *g=fopen("cmlsc.out","w");

	fscanf(f,"%d%d",&lungime_sir1,&lungime_sir2);
	
	int *sir1=calloc(lungime_sir1,sizeof(int));
	int *sir2=calloc(lungime_sir2,sizeof(int));
	Hash *hash=calloc(256,sizeof(Hash));
	
	for(int i=0;i<lungime_sir1;i++)
	{
		fscanf(f,"%d",&(sir1[i]));
		hash[sir1[i]].exista=1;
		hash[sir1[i]].pozitie=i;
	}

	for(int i=0;i<lungime_sir2;i++)
		fscanf(f,"%d",&(sir2[i]));

	
	int lungime_subsir;
	int lungime_subsir_maxima=0;
	int ultima_pozitie;

	int solutie_finala[lungime_sir2];
	int solutie_posibila[lungime_sir2];

	for(int i=0;i<lungime_sir2;i++)
	{
		lungime_subsir=0;
		ultima_pozitie=-1;		

		for(int j=i;j<lungime_sir2;j++)
		{
			if(hash[sir2[j]].exista==1)
			{
					if(lungime_subsir==0)
					{
						ultima_pozitie=hash[sir2[j]].pozitie;
						lungime_subsir++;
				
						if(lungime_subsir>lungime_subsir_maxima)
						{
							lungime_subsir_maxima=lungime_subsir;
							solutie_finala[lungime_subsir-1]=sir2[j];
							
						}
						solutie_posibila[lungime_subsir-1]=sir2[j];
							
					}
					else
					{
						if(ultima_pozitie<hash[sir2[j]].pozitie)
						{
							ultima_pozitie=hash[sir2[j]].pozitie;
							lungime_subsir++;
							solutie_posibila[lungime_subsir-1]=sir2[j];

							if(lungime_subsir>lungime_subsir_maxima)
							{
								for(int k=0;k<lungime_subsir;k++)
									solutie_finala[k]=solutie_posibila[k];							
								lungime_subsir_maxima=lungime_subsir;
							}						

						}

					}

			}	

		}


	}
	
	fprintf(g,"%d\n",lungime_subsir_maxima);
	
	for(int i=0;i<lungime_subsir_maxima;i++)
	{
			if(i==lungime_subsir_maxima-1)
				fprintf(g,"%d\n",solutie_finala[i]);
			else
				fprintf(g,"%d ",solutie_finala[i]);

	}


	free(sir1);
	free(sir2);
	free(hash);

	fclose(f);
	fclose(g);

	return 0;
}
