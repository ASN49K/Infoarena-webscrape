#include <stdio.h>

void swap(int &a,int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int euclid2(int a, int b)
{
	int r;
	do{
		r = a % b;
		a = b;
		b = r;
	}
	while(r>0);

	return b;
	
}

int main()
{
	FILE *f;
	FILE *g;
	int a, b;
	int T;
	int gcd;
	
	f=fopen("euclid2.in","r");
	g=fopen("euclid2.out","w");
	fscanf(f,"%d",&T);
	
	for(int i=0;i<T;i++)
	{
		fscanf(f,"%d %d",&a,&b);
		if(a<b)
		{
			swap(a,b);
		}
		gcd = euclid2(a,b);
		fprintf(g,"%d\n",gcd);
	}
	
	fclose(f);
	fclose(g);

	return 0;
}