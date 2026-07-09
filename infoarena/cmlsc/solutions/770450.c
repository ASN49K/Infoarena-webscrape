#include <stdio.h>
#include <stdlib.h>
#define max(a,b) ((a)>(b) ? (a) : (b))
#define MMAX 1025
#define NMAX 1025
int main()
{
    int n,m,i,j;
    int a[NMAX][MMAX] =  {{0}}, v1[NMAX],v2[MMAX],rez[NMAX],lgmax,t;
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    scanf("%i %i",&n,&m);
    for (i=1;i<=n;i++) scanf("%i",v1+i);
    for (i=1;i<=m;i++) scanf("%i",v2+i);
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (v1[i]==v2[j]) a[i][j] = a[i-1][j] + 1;
            else a[i][j] = max(a[i][j-1],a[i-1][j]);
    lgmax = a[n][m];
    t = lgmax;
    printf("%i\n",lgmax);
    for (i=n,j=m;lgmax!=0;)
        {
                if (v1[i]==v2[j]) {rez[lgmax--] = v1[i];i--;j--;}
                else if (a[i][j-1] > a[i-1][j]) j--;
                else i--;
        }
    for (i=1;i<=t;i++) printf("%i ",rez[i]);

    return 0;
}
