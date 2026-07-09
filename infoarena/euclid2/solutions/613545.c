#include <stdio.h>

int gcd(int, int);

int
main(void)
{
	int a, b, T;

	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	
	while(T)
	{
		scanf("%d%d", &a, &b);
		printf("gcd dintre %d si %d este: %d\n", a, b, gdc(a, b));		
		T--;
	}

	return 0;
}

int 
gcd(int a, int b)
{
	if(b == 0)
		return a;
	else
		return gcd(b, a % b);
}