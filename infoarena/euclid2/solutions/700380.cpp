#include<stdio.h>
FILE *f=fopen("euclid2.in","r");
FILE *g=fopen("euclid2.out","w");
int t;
long a,b;
int main()
{
	int i;
	fscanf(f,"%d",&t);
	for(i=1;i<=t;i++)
	{
		fscanf(f,"%ld%ld",&a,&b);
		while(a!=b)
		{
			if(a>b) a=a-b;
			else b=b-a;
		}
		fprintf(g,"%ld\n",a);
	}
	fclose(f);
	fclose(g);
	return 0;
}
