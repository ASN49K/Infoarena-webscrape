#ifdef WIN32
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>


void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int cmmdc(int a, int b)
{
	if (a > b)
		swap(&a, &b);

	while (a != 0)
	{
		b %= a;
		swap(&a, &b);
	}

	return b;
}


int main()
{
	freopen("euclid2.in", "rt", stdin);
	freopen("euclid2.out", "wt", stdout);

	int t;
	scanf("%d", &t);
	for (int a, b, i = 0; i < t; i++)
	{
		scanf("%d%d", &a, &b);
		printf("%d\n", cmmdc(a, b));
	}

	return 0;
}
