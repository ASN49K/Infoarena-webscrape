#include <stdio.h>


int main()
{
	int x;
	FILE * fin , * fout;

	fin = fopen("test.in","r");
	fout = fopen("test.out","w");

		fscanf(fin,"%d",&x);
		fprintf(fout,"%d",x);

	fclose(fin);
	fclose(fout);
	return 0;
}