#include<stdio.h>
#include<algorithm>

FILE *in,*out;

//functii
int cmmdc(int x,int y);

//variabile
int a,b,n;

int main(void)
{
	in=fopen("euclid2.in","rt");
	out=fopen("euclid2.out","wt");
	
	fscanf(in,"%d",&n);
	
	for(int i=1 ; i<=n ; ++i)
	{	
		fscanf(in,"%d%d",&a,&b);
		fprintf(out,"%d\n",cmmdc(a,b));
	}
	fclose(in);
	fclose(out);
	return 0;
}

int cmmdc(int x,int y)
{
	if(!y)
		return x;
	return cmmdc(y,x%y);
}
