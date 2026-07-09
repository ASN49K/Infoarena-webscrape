#include<stdio.h>

int a,b,r;

void citire()
{
freopen("euclid2.in","r",stdin);
scanf("%d%d", &a, &b);
fclose(stdin);
}

void cmmdc()
{
	int w=a;
	int q=b;
	while (q>0)
	{
		r=w%q;
		w=q;
		q=r;
	}
	printf("%d", w);
}

int main()
{
	freopen("euclid2.out","w",stdout);
	citire();
	cmmdc();
	fclose(stdout);
	return 0;
}