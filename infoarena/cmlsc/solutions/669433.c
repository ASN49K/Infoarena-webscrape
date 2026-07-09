#include <stdio.h>

#define IN "cmlsc.in"
#define OUT "cmlsc.out"
#define N 1100

short A[N], B[N];

void cmlsc(int, int);

int main(void) {

    int n1, n2, i;

    freopen(IN, "r", stdin); freopen(OUT, "w", stdout);

    scanf("%d %d", &n1, &n2);

    for(i = 1; i <= n1; ++i)
        scanf("%hd", &A[i]);

    for(i = 1; i <= n2; ++i)
        scanf("%hd", &B[i]);

    cmlsc(n1, n2);

    return 0;
}

void cmlsc(int n1, int n2) {

    int L_max[N][N], i, j, lmax = 0;

    for(i = 1; i <= n1; ++i)
        L_max[i][0] = 0;
    for(i = 1; i <= n2; ++i)
        L_max[0][i] = 0;

    for(i = 1; i <= n1; ++i)
        for(j = 1; j <= n2; ++j) {

            if(A[i] == B[j])
                L_max[i][j] = L_max[i - 1][j - 1] + 1;
            else
                L_max[i][j] = (L_max[i][j - 1] > L_max[i - 1][j]) ?
                               L_max[i][j - 1] : L_max[i - 1][j];

            if(L_max[i][j] > lmax)
                lmax = L_max[i][j];
        }

    printf("%d\n", lmax);
}

