#include <stdio.h>
#define IN "euclid2.in"
#define OUT "euclid2.out" 

unsigned int gcd( unsigned int a, unsigned int b)
{
	unsigned int t;
	
	while ( b != 0 )
	{
		t = a;
		b = a % b;
		a = t;
	}
	
	return b;
}

int main()
{
	unsigned int t, a, b;
	FILE *f, *g;
	
	fopen(f, "euclid2.in", "r");
	fopen(g, "euclid2.out", "w");
	
	fscanf(f,"%u", &t);
	
	while( t>0 )
	{
		fscanf(f,"%u %u", &a, &b);
		fprintf(g,"%u\n", gcd(a,b));
		t--;
	}
	
	fclose(f);
	fclose(g);
	
	return 0;
}