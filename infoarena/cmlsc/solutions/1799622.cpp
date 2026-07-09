#include <stdio.h>
#include <algorithm>
using namespace std;

int m, n, s1[1024], s2[1024], D[1024][1024], sol[1024],k;

int main()
{
    int i, j;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);
    for (i = 1; i <= m; ++i)     scanf("%d", &s1[i]);
    for (i = 1; i <= n; ++i)     scanf("%d", &s2[i]);

    for (i = 1; i <= m; ++i)
    for (i = 1; i <= n; ++i)
            if (s1[i] == s2[j])   D[i][j] =1+D[i-1][j-1];
            else                  D[i][j] = max(D[i-1][j], D[i][j-1]);

    for (i=m,j=n;i;)
        if (s1[i]==s2[j]) sol[++k]=s1[i],--i,--j;
        else if (D[i-1][j] < D[i][j-1])      --j;
        else                             --i;

    printf("%d\n", k);
    for (i = k; i; --i)   printf("%d ", sol[i]);

}
