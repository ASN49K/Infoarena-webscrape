#include <stdio.h>
#include <stdlib.h>

int M, N, A[1024], B[1024], sir[1024], bst, cnt;

void result(char msg[], int p)
{
    fprintf(stderr, msg);
    printf("%d", p);
    exit(0);
}

int subsir(int *X, int l1, int *S, int l2)
{
    int i, j = 1;

    for (i = 1; i <= l2 && j <= l1; i++)
        for (; j <= l1 && X[j] != S[i]; ++j);
    return j <= l1;
}

int main(void)
{
    int i;
    FILE *f;
    
    f = fopen("cmlsc.in", "r");
    if (!f) result("Fisier de intrare lipsa!", 0);
    if (fscanf(f, "%d %d", &M, &N) != 2)
        result("Fisier de intrare corupt!", 0);
    if (M > 1024 || N > 1024 || M < 1 || N < 1)
        result("Fisier de intrare corupt!", 0);
    for (i = 1; i <= M; i++)
    {
        if (fscanf(f, "%d", &A[i]) != 1)
            result("Fisier de intrare corupt!", 0);
        if (A[i] < 1 || A[i] > 256)
            result("Fisier de intrare corupt!", 0);
    }
    for (i = 1; i <= N; i++)
    {
        if (fscanf(f, "%d", &B[i]) != 1)
            result("Fisier de intrare corupt!", 0);
        if (B[i] < 1 || B[i] > 256)
            result("Fisier de intrare corupt!", 0);
    }

    f = fopen("cmlsc.ok", "r");
    if (!f) result("Fisier ok lipsa!", 0);
    if (fscanf(f, "%d", &bst) != 1)
        result("Fisier ok corupt!", 0);

    f = fopen("cmlsc.out", "r");
    if (!f) result("Fisier de iesire lipsa!", 0);
    if (fscanf(f, "%d", &cnt) != 1)
        result("Fisier de iesire corupt!", 0);

    if (cnt != bst)
        result("Lungime incorecta!", 0);
        
    for (i = 1; i <= cnt; i++)
        if (fscanf(f, "%d", &sir[i]) != 1)
            result("Fisier de iesire corupt!", 0);

    if (!subsir(A, M, sir, cnt))
        result("Subsir incorect!", 0);
    if (!subsir(B, N, sir, cnt))
        result("Subsir incorect!", 0);

    result("Raspuns corect!", 10);
        
    return 0;
}

