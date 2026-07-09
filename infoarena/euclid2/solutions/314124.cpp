#include<cstdio>
using namespace std;

int main()
{
	int a,b,c,i,t;
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");
	fscanf(f,"%d",&t);
	for (i=1;i<=t;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		if (b>a)
		{
			c=a;
			a=b;
			b=c;
		}
		c=a%b;
		while(c)
		{
			a=b;
			b=c;
			c=a%b;
		}
		fprintf(g,"%d",b);
		fprintf(g,"\n");
	}
	fclose(f);
	fclose(g);
	return 0;
}