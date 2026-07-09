#include<stdio.h>
FILE *in=fopen("euclid2.in","r"),*out=fopen("euclid2.out","w");
long int t,a,b,aux;
int main()
{
	fscanf(in,"%ld",&t);
	while(t)
	{
		fscanf(in,"%ld %ld",&a,&b);
		while(b)
		{
			aux=a%b;
			a=b;
			b=aux;
		}
		fprintf(out,"%ld\n",a);
		t--;
	}
	fcloseall();
	return 0;
}
