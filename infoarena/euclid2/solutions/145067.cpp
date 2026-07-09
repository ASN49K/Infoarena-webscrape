#include<stdio.h>

int main()
{
	freopen("euclid2.in","r",stdin);
	freopen("euclid2.out","w",stdout);
	int a,b,r;
	scanf("%d%d", &a, &b);
	while (r>1)
	{
		r=a%b;
		a=b;
		b=r;
	}
	printf("%d", a);
	fclose(stdout);
	fclose(stdout);
	return 0;
}