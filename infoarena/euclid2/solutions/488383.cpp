#include <cstdio>

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	int t, a, b, r;
	for ( scanf("%d", &t); t; --t )
	{
		scanf("%d %d", &a, &b);
		while(b)
		{
			r = a % b;
			a = b;
			b = r;
		}
		printf("%d\n", a);
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}
