#include <stdio.h>

int T,A,B;
FILE *f1,*f2;

int euclid(int a, int b)
{
	if (!b) 
		return  a;
	else
		return euclid(b,a%b);
}

int main(void)
{
	f1=fopen("euclid2.in","r");
	f2=fopen("euclid2.out","w");
	
	fscanf(f1,"%d",&T);
	while (T)
	{
		T--;
		fscanf(f1,"%d %d",&A,&B);
		fprintf(f2,"%d\n",euclid(A,B));
	}
	
	return 0;
}
