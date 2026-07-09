#include <stdio.h>

int gcd(int a, int b)
{
	int tmp;
	
	if (a < b) 
		return gcd(b, a);

	while(b) {
		tmp = b;
		b = a % b;
		a = tmp;
	}

	return a;
}
		

int main(void)
{
	int i, T, a, b, d;
	
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	
	for (i = 0; i < T; i++) {
		scanf("%d %d", &a, &b);
		//fprintf(stderr, "Computing for (%d, %d) = ", a, b);
		d = gcd(a, b);
	//	fprintf(stderr, "%d\n", d);
		printf("%d\n", d);
	}

	return 0;
}
		
	
	
