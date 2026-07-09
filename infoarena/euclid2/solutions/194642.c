#include <stdio.h>

int main (void)
{
	unsigned int test, nrTeste, a, b, bak;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w+", stdout);
	
	scanf("%u\n", &nrTeste);
	for (test=0; test<nrTeste; ++test) {
		scanf("%u %u\n", &a, &b);
		while (b) {
			bak = b;
			b = a%b;
			a = bak;
		}
		printf("%u\n", a);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
