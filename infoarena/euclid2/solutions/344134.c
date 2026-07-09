#include "stdio.h" 

int euclid(int a, int b)
{
 while(a%b) 
	{ 
 	 int aux = b; 
     b = a%b; 
	 a = aux; 
	} 
 return b;
}

int main(void) 
{ 
 
		FILE *fin, *fout; 
		int T;
		int a, b; 
		if((fin = fopen("euclid2.in", "r"))==NULL) 
			return -1; 
		if((fout = fopen("euclid2.out", "w"))==NULL) 
			return -1; 
		fscanf(fin, "%d\n", &T);
		for(int i=0; i<T; i++)
			{
				fscanf(fin, "%d %d", &a, &b); 
				fprintf(fout, "%d\n", euclid(a, b)); 		
			}
		fclose(fin); 
		fclose(fout); 
		return 0; 
}