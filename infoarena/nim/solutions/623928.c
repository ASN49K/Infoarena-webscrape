#include <stdio.h>

int main()
{
    freopen("nim.in", "r", stdin);
    freopen("nim.out", "w", stdout);
    int t, n, a, b, i, j;
    b = 0;
    scanf("%d", &t);
    for (i=1; i<=t; ++i) {
        scanf("%d", &n);
        for (j=1; j<=n; ++j) {
	scanf("%d", &a);
	b = a^b;
        }
        if (b == 0)
	printf("NU\n");
        else
	printf("DA\n");
        b = 0;
    }
    return 0;
}
