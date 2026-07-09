#include <cstdio>
#include <algorithm>
using namespace std;
int const NMAX=1030;
int v1[NMAX],v2[NMAX], a[NMAX][NMAX],sol[NMAX];
int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w",stdout);
    int n,m,i,j;
    scanf("%d%d", &n, &m);
    for(i=1; i<=n; i++ )
        scanf("%d", &v1[i]);
    for(i=1; i<=m; i++ )
        scanf("%d", &v2[i]);

    for(i=1; i<=n; i++)
      for(j=1; j<=m; j++)
    {
        if(v1[i] == v2[j])
            a[i][j]=1+a[i-1][j-1];
        else
           a[i][j] = max(a[i-1][j], a[i][j-1]);
    }

    printf( "%d\n", a[n][m]);
    i = n;
    j = m;
   int  ind = 1;
    while(a[i][j] != 0)
    {
        if(v1[i] == v2[j])
        {
            sol[ind++] = v1[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j] > a[i][j-1])
            {
                i--;
            }
            else
                j--;
        }
    }
    ind--;
    for(i = ind; i>= 1; i--)
        printf("%d ", sol[i]);
           return 0;
}
