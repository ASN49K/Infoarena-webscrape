#include <stdio.h>

int cmmdc(int a, int b)
{
	while(a && b)
		if( a >= b )
			a %= b;
		else
			b %= a;
	return a | b;
}

int main()
{
	int a,b;
	FILE *f=fopen("euclid2.in","r");
	fscanf(f,"%d %d",&a,&b);
	fclose(f);
	f=fopen("euclid2.out","w");
	fprintf(f,"%d\n",cmmdc(a,b));
	fclose(f);
	return 0;
}
