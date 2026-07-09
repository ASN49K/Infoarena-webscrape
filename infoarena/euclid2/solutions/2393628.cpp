#include <cstdio>

int cmmdc(int a,int b)
{
	int c;
	while(b)
	{
		c=a%b;
		a=b;
		b=c;
	}
	return a;
}

int main()
{
	int n,i,a,b;
	FILE *intrare,*iesire;
	intrare=fopen("euclid2.in","r");
	iesire=fopen("euclid2.out","w");
	fscanf(intrare,"%d",&n);
	for(i=1;i<=n;i++)
	{
			fscanf(intrare,"%d %d",&a,&b);
			fprintf(iesire,"%d\n",cmmdc(a,b));
	}
	fclose(intrare);
	fclose(iesire);
	return 0;
}
