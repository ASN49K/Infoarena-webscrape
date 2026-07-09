#include <stdio.h>


int main(int argc, char *argv[])
{
	int x;
	FILE * fin , * fout;

	if(argc > 1)
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