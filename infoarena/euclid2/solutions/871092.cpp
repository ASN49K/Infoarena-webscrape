#include<stdio.h>
FILE *in,*out;
int n,a,b;
int imparte(int a,int b);
int main(void)
{
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
	fscanf(in,"%d",&n);
	for(int i=1;i<=n;++i)
	{
		fscanf(in,"%d%d",&a,&b);
		fprintf(out,"%d\n",imparte(a,b));
	}	
	fclose(in);
	fclose(out);
	return 0;
}

int imparte(int a,int b)
{
	if(!b)
		return a;
		return imparte(b,a%b);
	
}	
