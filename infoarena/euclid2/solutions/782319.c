#include <stdio.h>

unsigned int gcd( unsigned int a, unsigned int b)
{
	unsigned int t;
	
	while ( b != 0 )
	{
		t = a;
		b = a % b;
		a = t;
	}
	
	return a;
}

int main()
{
	unsigned int t, a, b;
	FILE *f, *g;
	
	f = fopen("euclid2.in", "r");
	g = fopen("euclid2.out", "w");
	
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