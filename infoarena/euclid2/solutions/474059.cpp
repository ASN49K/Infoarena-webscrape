#include<iostream>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
int cmmdc(int a,int b)
{
	if(!b)
		return a;
	else
		return cmmdc(b,a%b);
}
int main()
{
	int a,b,T;
	FILE *fi=fopen("euclid2.in", "r");
	FILE *fo=fopen("euclid2.out","w");
	fscanf(fi,"%d",&T);
	while(T)
	{
		fscanf(fi,"%d%d",&a,&b);
		fprintf(fo,"%d \n", cmmdc(a,b));
		T--;
	}
	fclose(fi);
	fclose(fo);
	return 0;
}
