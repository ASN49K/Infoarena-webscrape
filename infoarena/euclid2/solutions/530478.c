#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int cmmdc( int a, int b ){
	if ( !b)
	{
		return a; 
	}
	return cmmdc(b, a%b);
	
}

int main ()
{
	
	//printf("%d",sizeof(int)); 
	FILE *in = fopen("euclid2.in","r+");
	FILE *out = fopen("euclid2.out","w+"); 
	int n = 0; 
	fscanf(in,"%d",&n );
	
	int i; 
	for ( i=0; i<n; i++){
		int a,b; 
		fscanf(in,"%d%d",&a,&b); 
		fprintf(out,"%d\n",cmmdc(a,b));
		//printf("%d,%d\n",a,b); 
	}
	
	fclose( out ); 
	fclose( in ); 
	return 0; 
}
