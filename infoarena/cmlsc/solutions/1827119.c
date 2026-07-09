#include <stdio.h>
#include <stdlib.h>

#define NMAX 1024

int maxim(int x, int y)
{
    return (x > y) ? x : y;
}

int A[NMAX], B[NMAX];
int D[NMAX][NMAX];
int subsir[NMAX];

int main()
{
    int i, j;
    int N, M;
    int dim = 0;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d", &N);
    scanf("%d", &M);
    for(i = 1; i <= N; i ++)
        scanf("%d", &A[i]);
    for(j = 1; j <= M; j ++)
        scanf("%d", &B[j]);

    for(i = 1; i <= N; i ++)
        for(j = 1; j <= M; j ++)
            if(A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);

    i = N;
    j = M;

    while(i)
    {
        if(A[i] == B[j])
        {
            subsir[++dim] = A[i];
            i --;
            j --;
        }
        else if(D[i-1][j] < D[i][j-1])
            j --;
            else
                i --;
    }

    printf("%d\n", dim);
    for(i = dim; i >= 1; i --)
        printf("%d ", subsir[i]);

    return 0;
}
