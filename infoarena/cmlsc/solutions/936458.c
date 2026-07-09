#include <stdio.h>
#include <stdlib.h>



void BackTr(int** D, int A[], int B[],  int i, int j, FILE* f);
int main(void)
{
    FILE* f = fopen("cmlsc.in", "r");
    int N, M;
    int A[1025], B[1025];
    int i, j;


    fscanf(f, "%d%d", &N, &M);

    int** D = (int**)malloc(sizeof(int*)*(N+1));


    for (i = 0; i <= N; i++)
        D[i] = (int*)malloc(sizeof(int)*(M+1));

    for (i = 1; i <= N; i++)
        fscanf(f, "%d", &A[i]);
    for (i = 1; i <= M; i++)
        fscanf(f, "%d", &B[i]);
    fclose(f);

    f = fopen("cmlsc.out", "w");

    for (i = 0; i <= N; i++)
        D[i][0] = 0;
    for (i = 0; i <= M; i++)
        D[0][i] = 0;



    for (i = 1; i <= N; i++)
        for (j = 1; j <= M; j++)
            if (A[i] == B[j])
                D[i][j] = D[i-1][j-1] + 1;
            else D[i][j] = (D[i-1][j] > D[i][j-1] ? D[i-1][j] : D[i][j-1]);
    BackTr(D, A, B, N, M, f);
    fclose(f);
return 0;
}

void BackTr(int** D, int A[], int B[],  int i, int j, FILE* f)
{
    if (i == 0 || j == 0)
        return;
    else
    if (A[i] == B[j])
    {
        BackTr(D, A, B, i-1, j-1, f);
        fprintf(f, "%d ", A[i]);
    }
    else
    if (D[i][j-1] > D[i-1][j])
        BackTr(D, A, B, i, j-1, f);
    else
        BackTr(D, A, B, i-1, j, f);
}
