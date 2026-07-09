#include <cstdio>

unsigned int gcd(const unsigned int a, const unsigned int b)
{
    if (b) return gcd(b, a % b);
    else
	return a;
}

int main()
{
    int t;

    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);

    scanf("%u", &t);

    while (t--)
    {
	unsigned int a, b;

	scanf("%u %u", &a, &b);
	printf("%u\n", gcd(a, b));
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
