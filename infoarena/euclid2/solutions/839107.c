#include <stdio.h>


int main(char * args[])
{
	int x;
	FILE * fin , * fout;

	if(args[0] != NULL)
	{
	fin = fopen("test.in","r");
	fout = fopen("test.out","w");

		fscanf(fin,"%d",&x);
		fprintf(fout,"%d",x);
	} else 
	{
	fin = fopen("euclid2.in","r");
	fout = fopen("euclid2.out","w");
		fscanf(fin,"%d",&x);
		fprintf(fout,"%d",x);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}