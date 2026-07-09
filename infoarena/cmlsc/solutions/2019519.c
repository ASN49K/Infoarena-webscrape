#include <stdio.h>

#define max(A, B) ((A > B) ? A : B)
#define N 1024

int main ()
{
    int FirstLength, SecondLength, A[N], B[N], D[N][N], sir[N], length = 0;

    freopen ("clmsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);

    scanf ("%d %d", &FirstLength, &SecondLength);
    for (int i = 1; i <= FirstLength; ++i)
        scanf ("%d", &A[i]);
    for (int i = 1; i <= SecondLength; ++i)
        scanf ("%d", &B[i]);

    for (int i = 1; i <= FirstLength; ++i)
        for (int j = 1; j <= SecondLength; ++j)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = max (D[i - 1][j], D[i][j - 1]);

    for (int i = FirstLength, j = SecondLength; i != 0; )
        if (A[i] == B[j])
            sir[++length] = A[i], --i, --j;
        else
            if (D[i - 1][j] < D[i][j - 1])
                --j;
            else
                --i;

    printf("%d\n", length);
    for (int i = length; i != 0; --i)
        printf("%d%c", sir[i], (i > 1) ? ' ' : '\n');

    return 0;
}