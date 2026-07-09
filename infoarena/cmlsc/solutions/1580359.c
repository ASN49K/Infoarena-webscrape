#include <stdio.h>
 
#define maxim(a, b) ((a > b) ? a : b)
#define FOR(i, a, b) for (i = a; i <= b; ++i)
#define NMax 1024
 
int M, N, A[NMax], B[NMax], D[NMax][NMax], sir[NMax], bst;
FILE *in, *out;

int main()
{
    int i, j;
     
    in = fopen("cmlsc.in", "r");
    out = fopen("cmlsc.out", "w");
 
    fscanf(in, "%d %d", &M, &N);
    FOR (i, 1, M)
        fscanf(in, "%d", &A[i]);
    FOR (i, 1, N)
        fscanf(in, "%d", &B[i]);
 
    FOR (i, 1, M)
        FOR (j, 1, N)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i-1][j-1];
            else
                D[i][j] = maxim(D[i-1][j], D[i][j-1]);
 
    for (i = M, j = N; i; )
        if (A[i] == B[j])
            sir[++bst] = A[i], --i, --j;
        else if (D[i-1][j] < D[i][j-1])
            --j;
        else
            --i;
 
    fprintf(out, "%d\n", bst);
    for (i = bst; i; --i)
        fprintf(out, "%d ", sir[i]);
    
    fclose(in);
    fclose(out);
    return 0;
}