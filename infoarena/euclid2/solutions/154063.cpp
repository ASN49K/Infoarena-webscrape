#include<stdio.h>

long cmmdc(long a, long b)
{
	if (b)
		return cmmdc(b, a%b);
	 return a;
}

int main()
{
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
	
	long t, i, a, b;
	scanf("%ld", &t);
	for (i=1; i<=t; i++)
	{
        scanf("%ld %ld", &a, &b);
	    printf("%ld\n", cmmdc(a,b));
    }
	fclose(stdout);
	return 0;
}
