#include <stdio.h>
FILE *fin, *fout;
int t, a, b;
int gcd(int x, int y)
{
	if(y == 0) return x;
	return gcd(y, x%y);
}
int main()
{
	fin = freopen("euclid2.in", "r", stdin);
	fout = freopen("euclid2.out", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i< t; ++i)
	{
		scanf("%d %d", &a, &b);
		printf("%d\n", gcd(a, b));
	}
	fclose(fin);
	fclose(fout);
	return 0;
}
