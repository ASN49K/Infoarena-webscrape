#include <stdio.h>

int gcd( int a, int b)
{
	int t;
	
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
	int t, a, b;
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