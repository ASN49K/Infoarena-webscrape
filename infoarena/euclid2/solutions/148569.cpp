#include <stdio.h>
int cmmdc(int n,int m)
{
	if(m==0) return n;
	else return cmmdc(n,m%n);
}
int main()
{
	int a,b;
	FILE *in=fopen("euclid2.in","rt");
	FILE *out=fopen("euclid2.out","wt");
	fscanf(in,"%d %d",&a,&b);
	fprintf(out,"%d",cmmdc(a,b));
	fclose(in);
	fclose(out);
	return 0;
}
