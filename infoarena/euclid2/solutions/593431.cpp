#include<stdio.h>
long euclid(long a, long b)
{
	long tmp;
	while(b>0)
	{
		tmp=b;
		b=a%b;
		a=tmp;
	}
return a;
}
int main()
{
	FILE *f,*g;
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	int t;
	fscanf(f,"%d",&t);
	long a,b;
	for(int i=0;i<t;i++)
	{
		fscanf(f,"%ld %ld",&a,&b);
		fprintf(g,"%ld \n",euclid(a,b));
	}
	
fclose(f);
fclose(g);
return 0;
}