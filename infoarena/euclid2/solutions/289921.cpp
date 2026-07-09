#include<stdio.h>
FILE *in=fopen("euclid2.in","r"),*out=fopen("euclid2.out","w");
long int n,a,b;
long int gcd(long int x, long int y)
{
	if(x%y==0) return y;
	return gcd(y,x%y);
}
int main()
{
	fscanf(in,"%ld",&n);
	for(int i=1;i<=n;i++)
		{
			fscanf(in,"%ld %ld",&a,&b);
			fprintf(out,"%ld\n",gcd(a,b)); //greatest common divisor
		}
	fcloseall();
	return 0;
}