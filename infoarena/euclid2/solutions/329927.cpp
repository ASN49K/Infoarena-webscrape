// Euclid.cpp : Defines the entry point for the console application.
//

#include<stdio.h>

int t, a, b, aux;

int main()
{
	FILE *ofile,*ifile;
	
	ifile = fopen("euclid2.out", "w");
	ofile = fopen("euclid2.in", "r");
	fscanf(ofile, "%i", &t);
	for(int i=0; i<t; i++){
		fscanf(ofile, "%i %i", &a, &b);
		if(a<b){
			aux=a;
			a=b;
			b=aux;
		}
		while(b>1){
			aux = a%b;
			a=b;
			b=aux;
		}
		if(b==1) fprintf(ifile,"%i\n",1);
		else fprintf(ifile,"%i\n",a);
	}
	fclose(ofile);
	fclose(ifile);

	return 0;
}

