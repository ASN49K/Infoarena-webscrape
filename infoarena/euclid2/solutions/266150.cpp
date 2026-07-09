#include<stdio.h>
FILE *f=fopen("euclid2.in","r"), *g=fopen("euclid2.out","w");
int n,i,a,b;
inline int cmmdc(int a, int b)
{
	
	if(b==0) return a;
	int d;
	d=cmmdc(b,a%b);
	return d;
}

int main()
{
	fscanf(f,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		if(a>b) a^=b^=a^=b;
		fprintf(g,"%d\n",cmmdc(a,b));
	}
	
	fclose(f);
	fclose(g);
	return 0;
}