#include <stdio.h>

int numar_elemente;
int numar1, numar2;

int euclid(int numar1, int numar2)
{
	if( numar1 == numar2 ) return numar1;

	if( numar1 > numar2 ) euclid(numar1 - numar2, numar2);
	else euclid (numar1, numar2 - numar1);


}

int main()
{
	
	FILE *fr;
	FILE *fw;

	fr = fopen("euclid2.in","r");
	fw = fopen("euclid2.out","a+");

	if(!fr) printf("Nu s-a deschis fisierul!\n");

	fscanf(fr,"%d",&numar_elemente);
	
	for(;numar_elemente;numar_elemente--)
	{
		fscanf(fr,"%d",&numar1);
		fscanf(fr,"%d",&numar2);

		int result = euclid(numar1,numar2);
		fprintf(fw,"%d\n",result);
	}

	return 0;
}