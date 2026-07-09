#include<stdio.h>
int a, b, t;

int main(void)
{
	int i, r;
	freopen ("euclid2.in", "r", stdin); freopen ("euclid2.out", "w", stdout);
	//FILE *f=fopen("vector.in","r"); FILE *g=fopen("vector.out","w");
	
	scanf("%d", &t);
	for(i=1; i<=t; i++)
	{
		scanf("%d %d", &a, &b);
		r=a%b;
		while(r)
		{
			a=b;
			b=r;
			r=a%b;
		}
		printf("%d\n", b);
	}
	return 0;
}