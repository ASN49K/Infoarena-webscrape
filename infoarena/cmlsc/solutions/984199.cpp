#include <cstdio>
#include <algorithm>
using namespace std;

const int NMAX = 1027;

int D[NMAX][NMAX], A[NMAX], B[NMAX], R[NMAX];

int main () {

    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    int N, M, i, j, s = 0;
    scanf ("%d%d", &N, &M);
    for (i = 1; i <= N; ++i)
        scanf ("%d", A + i);
    for (i = 1; i <= M; ++i)
        scanf ("%d", B + i);
    for (i = 1; i <= N; ++i)
        for (j = 1; j <= M; ++j)
            D[i][j] = A[i] == B[j] ? D[i - 1][j - 1] + 1 : max (D[i - 1][j], D[i][j - 1]);
    while (N)
        if (A[N] == B[M])
            R[++s] = A[N--], --M;
        else
            if (D[N - 1][M] < D[N][M - 1])
                --M;
            else
                --N;
    printf ("%d\n", s);
    while (s--)
        printf ("%d ", R[s + 1]);

}
