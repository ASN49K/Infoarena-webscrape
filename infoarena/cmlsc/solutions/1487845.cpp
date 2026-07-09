#include <bits/stdc++.h>
using namespace std;
const int nmax = 1025;
int mat[nmax][nmax], lg, sol[nmax];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);
    int n, m, a[nmax], b[nmax], i, j;
    scanf("%d %d", &n, &m);
    for(i=1; i<=n; i++)
        scanf("%d", &a[i]);
    for(i=1; i<=m; i++)
        scanf("%d", &b[i]);
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j]) mat[i][j]=mat[i-1][j-1]+1;
            else mat[i][j]=max(mat[i-1][j], mat[i][j-1]);
        }
    i=n; j=m;
    while(j)
    {
        if(a[i]==b[j])
        {
            sol[++lg]=a[i];
            i--;
            j--;
        }
        else if(mat[i-1][j]<mat[i][j-1]) j--;
        else i--;
    }
    printf("%d\n", lg);
    for(i=lg; i; i--)
        printf("%d ", sol[i]);
    return 0;
}
