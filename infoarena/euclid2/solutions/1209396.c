#include <stdio.h>

int cmmdc(int a, int b)
{
    while (b)
    {
        int rem = a % b;
        a = b;
        b = rem;
    }
    
    return a;
}

int cmmdc2(int a, int b)
{
    return (b == 0 ? a : cmmdc(b, a % b));
}

int main(void) 
{
	int T, a, b, i;
	freopen("euclid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);
    
	scanf("%d", &T);
	for (i = 1; i <= T; ++i)
	{
	    scanf("%d %d", &a, &b);
	    printf("%d\n", cmmdc(a, b));
	}
	
	return 0;
}
