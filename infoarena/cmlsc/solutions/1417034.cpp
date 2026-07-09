#include <stdio.h>

#define NMAX 1024
using namespace std;

int n,m,i,j,k,A[NMAX],B[NMAX],C[NMAX],D[NMAX][NMAX];

int maxi(int a, int b)
{
    if (a>b) return a;
    return b;
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for (i=1; i<=n; i++)
        scanf("%d", &A[i]);
    for (i=1; i<=m; i++)
        scanf("%d", &B[i]);

    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (A[i]==B[j]) D[i][j]=1+D[i-1][j-1];
            else D[i][j]=maxi(D[i-1][j],D[i][j-1]);

    i=n; j=m;
    while (D[i][j])
        if (A[i]==B[j])
        {
            C[++k]=A[i];
            i--; j--;
        }
        else if (D[i-1][j]<D[i][j-1]) j--;
        else i--;

    printf("%d\n", D[n][m]);
    for (i=k; i>=1; i--)
        printf("%d ", C[i]);

    return 0;
}
