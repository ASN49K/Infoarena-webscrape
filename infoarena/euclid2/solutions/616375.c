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
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));		
		T--;
	}

	return 0;
}

int 
gcd(int a, int b)
{
	int r;
	
	if(b == 0)
		return a;
	else
	{
		while(b)
		{
			r = a % b;
			a = b;
			b = r;
		}
	}
	
	return a;
}
