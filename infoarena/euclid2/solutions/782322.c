#include <stdio.h>

int gcd( int a, int b )
{
	int t;
	
	while ( b != 0 )
	{
		t = b;
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
	
	fscanf(f,"%d", &t);
	
	while( t>0 )
	{
		fscanf(f,"%d %d", &a, &b);
		fprintf(g,"%d\n", gcd(a,b));
		t--;
	}
	
	fclose(f);
	fclose(g);
	return 0;
}