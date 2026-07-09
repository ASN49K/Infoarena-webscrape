//#include "stdafx.h"
#include <iostream>
#include <fstream>
using namespace std;
FILE *in=fopen("euclid2.in","r");
FILE *out=fopen("euclid2.out","w");
long cmmdc(long a, long b)
{
	if(b==0) return a;
	else return cmmdc(b,a%b);
}
int main()
{
	int n;
	long x,y,p;
	fscanf(in,"%d",&n);
	for(int i=1;i<=n;i++)
	{
		fscanf(in,"%ld%ld",&x,&y);
		p=cmmdc(x,y);
		fprintf(out,"%ld\n",p);
	}
	fclose(in); fclose(out);
	return 0;
}

