#include <stdio.h>

int main() 
{
	int T, a, b, i;
	freopen("eculid2.in", "r", stdin);
	freopen("euclid2.out", "w", stdout);

	scanf("%d", &T);
	for (i = 1; i <= T; ++i)
	{
	    scanf("%d %d", &a, &b);
	    printf("%d\n", cmmdc(a, b));
	}
	
	return 0;
}

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
