#include <stdio.h>
FILE *fin, *fout;
int t, a, b;
int gcd(int a, int b)
{
	return (b == 0)?a:gcd(b, a%b);
}
int main()
{
	fin = freopen("euclid.in", "r", stdin);
	fout = freopen("euclid.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i< t;i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
