#include <iostream>

#define NMax 1030

using namespace std;

int N, M, A[NMax], B[NMax], Best[NMax][NMax];

void Read ()
{
    freopen ("cmlsc.in", "r", stdin);
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; ++i)
    {
        scanf ("%d", &A[i]);
    }
    for (int i=1; i<=M; ++i)
    {
        scanf ("%d", &B[i]);
    }
}

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
                Best[i][j]=Best[i-1][j-1]+1;
            }
            else
            {
                Best[i][j]=Max (Best[i-1][j], Best[i][j-1]);
            }
        }
    }
}

void Print (int i, int j)
{
    if (i<=0 or j<=0)
    {
        return;
    }
    if (A[i]==B[j])
    {
        Print (i-1, j-1);
        printf ("%d ", A[i]);
    }
    else
    {
        if (Best[i-1][j]>Best[i][j-1])
        {
            Print (i-1, j);
        }
        else
        {
            Print (i, j-1);
        }
    }
}

int main()
{
    Read ();
    CMLSC ();
    freopen ("cmlsc.out", "w", stdout);
    printf ("%d\n", Best[N][M]);
    Print (N, M);
    return 0;
}
