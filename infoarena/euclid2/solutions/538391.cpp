#include<stdio.h>

int cmmdc(int a,int b)
{
	if ( b == 0 ) return a;
	else return cmmdc ( b, a % b );
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
