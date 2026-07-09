#include <bits/stdc++.h>
#define NMAX 1024+5

using namespace std;

int M, N;
int A[NMAX], B[NMAX], dinamic[NMAX][NMAX], rez[NMAX], best;

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d%d", &M, &N);
    for(int i = 1; i <= M; ++i) scanf("%d", &A[i]);
    for(int i = 1; i <= N; ++i) scanf("%d", &B[i]);

    for(int i = 1; i <= M; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(A[i] == B[j])
                dinamic[i][j] = dinamic[i-1][j-1] + 1;
            else
                dinamic[i][j] = max(dinamic[i-1][j], dinamic[i][j-1]);
        }
    }

    for(int i = M, j = N; i; ) {
        if(A[i] == B[j]) {
            rez[++best] = A[i];
            --i, --j;
        }
        else {
            if(dinamic[i-1][j] < dinamic[i][j-1])
                --j;
            else
                --i;
        }
    }

    printf("%d\n", best);
    for(int i = best; i; --i)
        printf("%d ", rez[i]);
    return 0;
}
