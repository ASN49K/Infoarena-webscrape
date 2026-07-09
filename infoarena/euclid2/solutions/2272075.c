#include <stdio.h>

int gcd(int a, int b)
{
	while (b!=0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	FILE *inptr = fopen("euclid2.in","r");
	FILE *outptr = fopen("euclid2.out","w");

	int cases=0;

	fscanf(inptr,"%d",&cases);

	while (cases>0)
	{
		int a,b;
		fscanf(inptr,"%d %d",&a,&b);
		fprintf(outptr,"%d\n",gcd(a,b));
		cases--;
	}

	fclose(inptr);
	fclose(outptr);

	return 0;
}
