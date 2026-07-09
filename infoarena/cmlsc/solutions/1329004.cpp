#include <cstdio>
#define maxim(a, b) ((a > b) ? a : b)
#define MAX 1030

using namespace std;

int A[MAX], B[MAX];
int D[MAX][MAX]; // Programare Dinamica
int n, m;
int sol[MAX], r;

void citire () {
    int i;
    freopen ("cmlsc.in", "r", stdin);
    freopen ("cmlsc.out", "w", stdout);
    scanf ("%d %d", &n, &m);
    for (i=1; i<=n; ++i)
        scanf ("%d", &A[i]);
    for (i=1; i<=m; ++i)
        scanf ("%d", &B[i]);
}

void dinamic () {
    int i, j;
    D[1][1] = 1;
    for (i=1; i<=n; ++i) {
        for (j=1; j<=m; ++j) {
            if (A[i] == B[j])
                D[i][j] = 1+ D[i-1][j-1];
            else
                D[i][j] = maxim (D[i-1][j], D[i][j-1]);
        }
    }
}

void cstrsol () {
    int
        i = n,
        j = m;

    while (i) {
        if (A[i] == B[j])
            sol[++r] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
    }
}

void result () {
    int i;
    printf ("%d\n", r);
    for (i=r; i; --i)
        printf ("%d ", sol[i]);
}

int main()
{
    citire();
    dinamic ();
    cstrsol ();
    result ();
    return 0;
}
