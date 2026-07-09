#include <stdio.h>

int T,A,B;
int i;


int gcd(int A,int B)
{
	if(B!=0) return gcd(B,A%B);
	else return A;
}

void main()
{
	FILE *in = fopen("euclid2.in","r");
	FILE *out = fopen("euclid2.out","w");

	fscanf(in,"%d",&T);
	for(i=1;i<=T;i++)
	{
		fscanf(in,"%d",&A);
		fscanf(in,"%d",&B);
		fprintf(out,"%d\n",gcd(A,B));
	}
	fclose(in);
	fclose(out);
}