#include<iostream>
#include<stdio.h>

int cmmdc(int a,int b)
{
	if(a==0) return b;
	if(b==0) return a;
	if(a>b) return cmmdc(a%b,b);
	else return cmmdc(b%a,a);
}

int main()
{
	FILE *f=fopen("euclid2.in","r");
	FILE *g=fopen("euclid2.out","w");
	int T,a,b;
	fscanf(f,"%d",&T);
	while(T)
	{
		fscanf(f,"%d %d",&a,&b);
		T--;
		fprintf(g,"%d\n",cmmdc(a,b));
	}
	fclose(f);
	fclose(g);
	return 0;
}