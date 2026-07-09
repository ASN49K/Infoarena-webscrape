#include <stdio.h>

int euclid(int a, int b)
{
	int r;
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	return a;
}
int main ()
{ 
	int n , i , x , y;

	char input_filename[]="euclid12.in";
	char output_filename[]="euclid12.out";
	
	FILE *in = fopen(input_filename, "rt");
	FILE *out= fopen(output_filename, "wt");
	
	fscanf(in, "%d", &n);
	
	for (i = 0; i < n; i ++ ) {
		fscanf( in , "%d%d" , &x , &y ) ;
		fprintf( out , "%d\n" , euclid( x , y ) );

	}

	fclose(in);
	fclose(out);
	return 0;
}