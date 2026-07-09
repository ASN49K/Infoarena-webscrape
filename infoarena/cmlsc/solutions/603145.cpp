#include <iostream>

#define NMax 1050

using namespace std;

int N, M, A[NMax], B[NMax];
int Length[NMax][NMax];

inline int Max (int a, int b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

void CMLSC ()
{
    for (int i=1; i<=N; ++i)
    {
        for (int j=1; j<=M; ++j)
        {
            if (A[i]==B[j])
            {
                Length[i][j]=Length[i-1][j-1]+1;
            }
            else
            {
                Length[i][j]=Max (Length[i-1][j], Length[i][j-1]);
            }
        }
    }
}

void Print (int i, int j)
{
    if (i>0 && j>0)
    {
        if (A[i]==B[j])
        {
            Print (i-1, j-1);
            printf ("%d ", A[i]);
        }
        else
        {
            if (Length[i][j-1]>Length[i-1][j])
            {
                Print (i, j-1);
            }
            else
            {
                Print (i-1, j);
            }
        }
    }
}

int main()
{
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; ++i)
    {
        scanf ("%d", &A[i]);
    }
    for (int i=1; i<=M; ++i)
    {
        scanf ("%d", &B[i]);
    }
    CMLSC ();
    printf ("%d\n", Length[N][M]);
    Print (N, M);
    printf ("\n");
    return 0;
}
