// Dynamic Programming

#include <stdio.h>
#define NMAX 1024
#define maxim(a, b) ((a > b) ? a : b)

int M, N, A[NMAX], B[NMAX], D[NMAX][NMAX], sir[NMAX], length;

FILE *input, *output;

int main()
{
    int i, j;
    input = fopen("cmlsc.in", "r");
    output = fopen("cmlsc.out", "w");

    fscanf(input, "%d %d", &M, &N);
    for (i = 1; i <= M; ++i) fscanf(input, "%d", &A[i]);
    for (i = 1; i <= N; ++i) fscanf(input, "%d", &B[i]);

    for (i = 1; i <= M; ++i)
        for (j = 1; j <= N; ++j)
            if (A[i] == B[j]) D[i][j] = 1 + D[i-1][j-1];
            else D[i][j] = maxim(D[i-1][j], D[i][j-1]);


    for (i = M, j = N; i; )
    {
            if (A[i] == B[j])
                sir[++length] = A[i], --i, --j;
            else
            if (D[i-1][j] >= D[i][j-1]) --i;
            else --j;
    }
    fprintf(output, "%d\n", length);
    for (i = length; i; --i)
        fprintf(output, "%d ", sir[i]);
    return 0;
}
