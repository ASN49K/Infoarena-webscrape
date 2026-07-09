#include <cstdio>
typedef short int hint;
#define FOR(i,a,b) for (hint i=a; i<=b; ++i)

hint M, N, A[1050], B[1050], T[1050][1050], s[1050];

int main () {

    hint i, j, m=0;

    freopen("cmlsc.in","rt",stdin);
    freopen("cmlsc.out","wt",stdout);

    scanf("%hd %hd", &M, &N);
    FOR (i,1,M) scanf("%hd", &A[i]);
    FOR (i,1,N) scanf("%hd", &B[i]);

    FOR (i,1,M) {
        FOR (j,1,N) {
            if (A[i]==B[j]) T[i][j] = T[i-1][j-1]+1;
            else T[i][j] = (T[i-1][j] < T[i][j-1])? T[i][j-1]: T[i-1][j];
            printf("%hd ", T[i][j]);
        }
        printf("\n");
    }

    for (int i=M, j=N; i;) {
        if (A[i]==B[j]) s[m++] = A[i], --i, --j;
        else if (T[i-1][j] == T[i][j]) --i;
        else --j;
    }

    printf("%d\n", T[M][N]);
    for (--m;m+1;--m)
        printf("%d ", s[m]);

    return 0;
}
