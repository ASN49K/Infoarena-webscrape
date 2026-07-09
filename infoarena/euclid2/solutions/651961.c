#include <stdio.h>

int cmmdc(int a, int b)
{
	int tmp;
	if (a < b) {
		tmp = a;
		a = b;
		b = tmp;
	}
	int mod = a % b;
	if (mod == 0)
		return b;
	
	return cmmdc(b, mod);
		
}

int main()
{
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	int count = 0;
	scanf("%i", &count);

	int i, a, b;
	for (i = 0; i < count; i++) {
		scanf("%i%i", &a, &b);
		printf("%i\n", cmmdc(a, b));
	}

	return 0;
}
