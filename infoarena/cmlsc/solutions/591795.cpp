#include <stdio.h>
#define max(a,b) a > b ? a : b
#define nmax 1024

using namespace std;

int a[nmax], b[nmax], d[nmax][nmax], n, m, sir[nmax], k=0;

int main()
{ int i, j;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for (int i=1; i<=m; i++)
     scanf("%d", &a[i]);

    for (int i=1; i<=n; i++)
     scanf("%d", &b[i]);

    for (int i=1; i<=m; i++)
     for (int j=1; j<=n; j++)
      if (a[i] == b[j])
       d[i][j] = 1 + d[i-1][j-1];
       else
        d[i][j] = max(d[i-1][j],d[i][j-1]);

    for (i = m, j = n; i; )
     if (a[i] == b[j])
        sir[++k] = a[i], --i, --j;
      else if (d[i-1][j] < d[i][j-1])
         --j;
       else
          --i;

   printf("%d\n", k);

   for (i = k; i; --i)
     printf("%d ", sir[i]);


return 0;
}
