#include<stdio.h>
/*
int cmmdc(int a,int b)
{
	if ( b == 0 ) return a;
	else return cmmdc ( b, a % b );
}
*/
int cmmdc(int a,int b)
{
	if ( a == 0 ) return b;
	else if ( b == 0 ) return a;
	if ( a > b ) return cmmdc( a-b, b);
	else return cmmdc( a, b-a);
}

int main()
{
	FILE* f;
	FILE* ff;
	f=fopen("euclid2.in","r");
	int n;
	fscanf(f,"%d",&n);
	ff=fopen("euclid2.out","w");
	//fprintf(ff,"%d",cmmdc(56,42));
	
	int a,b;
	for (int i=0;i<n;i++)
	{
		fscanf(f,"%d%d",&a,&b);
		fprintf(ff,"%d\n",cmmdc(a,b));
	}
	
	return 0;
}
