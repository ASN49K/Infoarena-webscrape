#include <stdio.h>

int main()
{
	int n, a, b, aux;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	for(scanf("%d", &n); n > 0; n--)
	{
		scanf("%d %d", &a, &b);

		if(b > a)
		{
			aux = a;
			a = b;
			b = aux;
		}
		while(a%b)
		{
			aux = a%b;
			a = b;
			b = aux;
		}

		printf("%d\n", b);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}