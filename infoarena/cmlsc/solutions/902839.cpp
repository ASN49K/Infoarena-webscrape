#include <cstdio>

using namespace std;

int mat[1049][1049], a[1049], b[1049];

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    int n, m, maxi;
    scanf ("%d ", &n);
    scanf ("%d", &m);
    int i, j;
    for (i=1; i<=n; i++)
        scanf ("%d ", &a[i]);
    for (i=1; i<=m; i++)
        scanf ("%d ", &b[i]);
    for (i=1; i<=(n<m?n:m); i++)
        mat[1][i]=mat[i][1]=0;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=m; j++)
        {
            maxi=mat[i][j-1];
            if (maxi<mat[i-1][j])
                maxi=mat[i-1][j];
            if (a[i]==b[j])
                maxi++;
            mat[i][j]=maxi;
        }
    }
    printf ("%d\n", mat[n][m]);
    int k=0, q[1049];
    i=n; j=m;
    while (mat[i][j])
    {
        while (mat[i-1][j]==mat[i][j])
            i--;
        while (mat[i][j-1]==mat[i][j])
            j--;
        q[++k]=a[i];
        i--; j--;
    }
    for (i=k; i>0; i--)
        printf ("%d ", q[i]);
    return 0;
}
