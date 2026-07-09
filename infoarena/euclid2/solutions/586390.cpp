#include <stdio.h>

int tests, a, b;

int cmmdc(int a, int b)
{
    if (b==0) return a;
    return cmmdc(b, a % b);
}

int main(void)
{
    freopen("euclid2.in", "r", stdin);
    freopen("euclid2.out", "w", stdout);
    scanf("%d", &tests);

    while(tests>0)
    {
        scanf("%d %d", &a, &b);
        printf("%d\n", cmmdc(a, b));
		tests--;
    }        

    return 0;
}

