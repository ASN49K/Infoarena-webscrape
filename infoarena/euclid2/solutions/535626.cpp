#include<stdio.h>
#include<stdlib.h>

using namespace std;

int main()

{
	FILE *f,*g;
	g=fopen("euclid2.out","w");
	f=fopen("euclid2.in","r");
	long a,b,n;
	fscanf(f,"%ld",&n);
	while (n)
	{
		fscanf(f,"%ld %ld", &a,&b);
		while (b!=0)
		{
			long r=abs(a%b);
			a=b;
			b=r;
		}
		fprintf(g,"%ld\n",a);
		n--;
	}
	fclose(f);
	fclose(g);
	return 0;
}


	
	