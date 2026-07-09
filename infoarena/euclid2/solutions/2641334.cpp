#include "stdio.h"

int cmmdc(int a, int b)
{
	if( b==0 )
		return a;
	else
		return cmmdc(b, a%b);
}

int main()
{
	int n, a, b;

	FILE* in  = fopen("euclid2.in",  "r");
	FILE* out = fopen("euclid2.out", "w");

	fscanf(in, "%d", &n);
	for( int i=0; i<n; i++ )
	{
		fscanf(in, "%d %d", &a, &b);
		fprintf(out, "%d\n", cmmdc(a, b));
	}

	fclose(in);
	fclose(out);
}
