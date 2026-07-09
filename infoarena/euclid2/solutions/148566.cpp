#include <stdio.h>
long int cmmdc(long int n,long int m)
{
	if(m==0) return n;
	else return cmmdc(n,m%n);
}
int main()
{
	int a,b;
	FILE *in=fopen("euclid2.in","rt");
	FILE *out=fopen("euclid2.out","wt");
	fscanf(in,"%ld %ld",&a,&b);
	fprintf(out,"%ld",cmmdc(a,b));
	fclose(in);
	fclose(out);
	return 0;
}
