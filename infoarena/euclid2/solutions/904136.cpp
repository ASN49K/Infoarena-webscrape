#include <stdio.h>

FILE *f,*s;

int i,n,x,y;

int cmmdc(int a, int b)
{
	int r;
	
	while(b)
	{
		r=a%b;
		a=b;
		b=r;
	}
	
	return a;
}

int main()
{
	f=fopen("euclid2.in","r");
	s=fopen("euclid2.out","w");
	
	fscanf(f,"%d",&n);
	
	for(i=1;i<=n;i++)
	{
		fscanf(f,"%d %d",&x,&y);
		fprintf(s,"%d\n",cmmdc(x,y));
	}
	
	fclose(s);
	
	return 0;
}