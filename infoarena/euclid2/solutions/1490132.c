#include <stdio.h>

int cmmdc(int x, int y);
int main()
{
	FILE *in;
	FILE *out;
	int a, b;
	int T; //numar de perechi
	
	in = fopen("euclid2.in","r");
	out = fopen("euclid2.out","w");
	
	fscanf(in,"%d",&T);
	
	for(;T;--T)
	{
		fscanf(in,"%d %d",&a,&b);
		fprintf(out,"%d\n",cmmdc(a,b));
	}
	
	fclose(in);
	fclose(out);
	
	return 0;
}

int cmmdc(int x, int y)
{
	if(y==0) return x;
	else return cmmdc(y,x % y);
}
