#include <stdio.h>

int cmmdc(int a, int b)
{	
	if (b==0)
		return a;
	else
		return cmmdc(b,a%b);
}

int main()
{
	int T,a,b;
	FILE *f,*g;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%d",&T);
	while (T>0)
	{
		fscanf(f,"%d %d",&a,&b);
		fprintf(g,"%d\n",cmmdc(a,b));
	}
	return 0;
}
