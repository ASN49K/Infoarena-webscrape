#include <stdio.h>
#define nmax 1024

int a[nmax], b[nmax], s[nmax], n, m, nr=0, j=0;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &m, &n);

    for (int i=1; i<=m; ++i)
     scanf("%d", &a[i]);

    for (int i=1; i<=n; ++i)
     scanf("%d", &b[i]);

     for (int i=1; i<=m; ++i)
      {
          for (int k=1; k<=n; ++k)
           if ( a[i] == b[k] )
            {
                ++nr;
                s[++j]=a[i];
            }
      }

     printf("%d\n", nr);
     for (int i=1; i<=j; ++i)
      printf("%d ", s[i]);

return 0;
}
