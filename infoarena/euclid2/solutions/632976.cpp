#include<stdio.h>

using namespace std;

long int euclid_impartiri(long int a,long int b)
{	long int x;
	while(b!=0) {
		x=a%b;
		a=b;
		b=x;	}
	return  a;	
}

int main()
{	long int i,T,x,y;
	FILE *c,*d;
	c=fopen("euclid2.in","r");
	d=fopen("euclid2.out","w");
	fscanf(c,"%ld",&T);
	for(i=1;i<=T;i++)	{
		fscanf(c,"%ld %ld",&x,&y);
		fprintf(d,"%ld \n",euclid_impartiri(x,y));	}
	fclose(c);
	fclose(d);
	return 0;
}