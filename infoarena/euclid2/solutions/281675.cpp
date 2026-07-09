#include <cstdio>

int T, a, b;

int cmmdc(int a, int b)
{
    if (b == 0) return a;
    return cmmdc(b, a % b);
}

int main()
{
    freopen("euclid2.in","r",stdin);
    freopen("euclid2.out","w",stdout);

    scanf("%d", &T);
    for (; T; --T)
    {
	scanf("%d%d", &a, &b);
	printf("%d\n", cmmdc(a,b));
    }
    return 0;
}
