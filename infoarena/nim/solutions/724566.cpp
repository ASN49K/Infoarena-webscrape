#include<stdio.h>

FILE*f=fopen("nim.in","r");
FILE*g=fopen("nim.out","w");

int main () {
	
	int t;
	fscanf(f,"%d",&t);
	
	for ( ; t ; --t ){
		int n;
		fscanf(f,"%d",&n);
		
		int xor_sum = 0,x;
		for ( int i = 1 ; i <= n ; ++i ){
			fscanf(f,"%d",&x);
			xor_sum ^= x;
		}
		
		if ( xor_sum ){
			fprintf(g,"DA\n");
		}
		else{
			fprintf(g,"NU\n");
		}
	}
	
	fclose(f);
	fclose(g);
	
	return 0;
}
