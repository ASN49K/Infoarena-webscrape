#include <stdio.h>

int cmmdc (int a, int b)
{	
	while (b)
	{
		int r=a%b;
		a=b;
		b=r;
	}
	return a;
}
	
int main(void)
{
	int T, a, b;
	freopen ("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	scanf ("%d", &T);
	
	while (T)
	{
		scanf ("%d %d", &a, &b);
		int x=cmmdc(a,b);
		printf ("%d\n", x);
		T--;
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
