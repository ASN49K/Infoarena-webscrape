#include <stdio.h>


int tempa, tempb;

int cmmdc(int a,int b)
{
	int rest=0;
	int aux=0;
	if(a<b)
	{
		aux=a;
		a=b;
		b=aux;
	}
	do{
		rest=a%b;
		a=b;
		b=rest;
	}while(rest!=0);
	
	return a;
}

int main(){
	int player_unu=0,n;
	FILE *f = (FILE*) fopen("euclid2.in","r");
	FILE *g = (FILE*) fopen("euclid2.out", "w");

	fscanf(f, "%d", &n);
	for(int i=0;i<n;i++)
	{
		fscanf(f, "%d %d", &tempa, &tempb);
		fprintf(g, "%d\n", cmmdc(tempa, tempb));
	}
	
	fclose(f);
	fclose(g);
		
	return player_unu;
}