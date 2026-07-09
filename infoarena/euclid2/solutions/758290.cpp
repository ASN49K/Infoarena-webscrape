#include <stdio.h>


static int cmmdc(int a, int b);
int main(void)
{
	FILE *in, *out;
	int n = 0;
	in = fopen("euclid2.in","r");
	fscanf(in,"%d", &n);
	out = fopen("euclid2.out","w");
	int a,b;
	for(int i = 0; i<n; i++)
	{
		fscanf(in,"%d",&a);
		fscanf(in,"%d",&b);
		fprintf(out,"%d\n",cmmdc(a,b));
	}
	return 1;
}

static int cmmdc(int a, int b)
{
	if(b ==0) return a;
	else
		return cmmdc(b, a%b);
}