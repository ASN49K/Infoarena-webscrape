#include <stdio.h>
#define LL long long int
FILE *fin, *fout;
LL t, a, b;
LL gcd(LL a, LL b)
{
	return (b == 0)?a:gcd(b, a%b);
}
int main()
{
	fin = freopen("euclid.in", "r", stdin);
	fout = freopen("euclid.out", "w", stdout);
	scanf("%lld", &t);
	for(int i = 0; i< t;i++)
	{
		scanf("%lld%lld", &a, &b);
		printf("%lld\n", gcd(a, b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
