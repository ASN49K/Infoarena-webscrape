#include <cstdio>
#include <algorithm>

using namespace std;

#define FOR(i,n) for (int i = 0; i<(n); ++i)
#define FORE(i,n) for (int i = 0; i<=(n); ++i)
#define FORI(i,n1,n2) for (int i = n1; i<(n2); ++i)
#define FORIE(i,n1,n2) for (int i = n1; i<=(n2); ++i)

#define NMAX 1025

int N,M;
int S1[NMAX], S2[NMAX], sol[NMAX];
int A[NMAX][NMAX];

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &N, &M);
    FORIE(i,1,N)
        scanf("%d", &S1[i]);

    FORIE(i,1,M)
        scanf("%d", &S2[i]);

    int best = 0;

    FORIE(i,1,N)
    {
        FORIE(j,1,M)
        {
            if (S1[i] == S2[j])
            {
                A[i][j] = A[i-1][j-1] + 1;
            }
            else
            {
                A[i][j] = max(A[i][j-1], A[i-1][j]);
            }
            if (A[i][j] > best)
                best = A[i][j];
        }
    }

    int i = N, j = M, k=0;

    while (i)
    {
        if (S1[i] == S2[j])
        {
            sol[k++] = S1[i];
            --i;
            --j;
        }
        else if (A[i-1][j] < A[i][j-1])
            --j;
        else
            --i;
    }

    printf("%d\n", best);
    for (int i = k-1; i>=0; --i)
        printf("%d ", sol[i]);

    return 0;
}
