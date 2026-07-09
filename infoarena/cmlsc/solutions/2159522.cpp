#include <cstdio>
#include <algorithm>
#define Nmax 1026

using namespace std;

int n, m, A[Nmax], B[Nmax], c[Nmax][Nmax], sir[Nmax], best;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &n, &m);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=1; i<=m; i++)
    {
        scanf("%d", &B[i]);
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(A[i]==B[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            else
            {
                c[i][j]=max(c[i-1][j],c[i][j-1]);
            }
        }
    }
    for(int i=n, j=m ; i&&j ; )
    {
        if(A[i]==B[j])
        {
            sir[++best]=A[i];
            i--;
            j--;
        }
        else
        {
            if(c[i-1][j]<c[i][j-1])
            {
                j--;
            }
            else
            {
                i--;
            }
        }
    }
    printf("%d\n", best);
    for(int i=best; i; i--)
    {
        printf("%d ", sir[i]);
    }
    return 0;
}
