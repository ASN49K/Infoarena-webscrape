#include <stdio.h>

#define file_in "euclid2.in"
#define file_out "euclid2.out"

int main ( void ) {
	
	
		FILE *fin = fopen ( file_in ,"r");
		FILE *fout = fopen ( file_out , "w");
		
		int n;
		
		fscanf(fin,"%d",&n);
		
		int a, b, r;
	
		while(n--) {
			
			fscanf(fin,"%d %d", &a, &b);
			while(1) {
				
				r = a%b;
				if(r == 0 ) break;
				a=b;
				b=r;
			}
			
			fprintf(fout,"%d\n",b);
			
		}
		
		fclose(fin);
		fclose(fout);
		
		return 0;
}
