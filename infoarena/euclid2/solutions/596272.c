#include <stdio.h>

int Euclid(int a,int b)
{
	int r;
	r=a%b;
	while(r!=0)
	{
		a=b;
		b=r;
		r=a%b;
	}
	return b;
}

int main(int argc, char* argv[])
{
	int n;

	FILE* fpr = fopen("euclid2.in","r");
	FILE* fpw = fopen("euclid2.out","w");
	fscanf(fpr,"%d",&n);
	
	int i;
	for(i=0;i<n;++i)
	{
		int a,b;
		fscanf(fpr,"%d %d",&a,&b);
		fprintf(fpw,"%d\n",Euclid(a,b));
	}
	
	fclose(fpr);
	fclose(fpw);
	return 0;
}

