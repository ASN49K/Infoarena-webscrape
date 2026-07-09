#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* fin;
	FILE* fout;

	fin = fopen("euclid2.in", "r");
	fout = fopen("euclid2.out", "w");
	
	int n;
	fscanf(fin, "%d", &n);

	long a, b;
	for(int i=0;i<n;++i) 
	{
		fscanf(fin, "%ld %ld", &a, &b);
		if(a<b) 
		{
			int c = a;
			a = b;
			b = c;
		}
		
		int r;
		do 
		{
			r = a%b;
			a = b;
			b = r;
		}while(r != 0);
		fprintf(fout, "%d\n", a);
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
