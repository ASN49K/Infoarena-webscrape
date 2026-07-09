#include <stdio.h>
#define MAXSIZE 260

int M, N, max = -1;
short A[MAXSIZE], B[MAXSIZE], S[MAXSIZE], PS[MAXSIZE];


void read_data()
{
    int i;
    scanf("%d %d", &M, &N);
    for (i = 0; i < M; ++i)
        scanf("%hd", &A[i]);
    for (i = 0; i < N; ++i)
        scanf("%hd", &B[i]);
}

void write_solution()
{
    int i;
    printf("%d\n", max + 1);
    for (i = 0; i <= max; ++i)
        printf("%d ", S[i]);
}

void update_solution(int k)
{
    int i;
    max = k;
    for (i = 0; i <= max; ++i)
        S[i] = PS[i];
}

void find_solution(int i, int j, int k)
{
    if (A[i] == B[j])
    {
        ++k;
        PS[k] = A[i];
        if (k > max)
            update_solution(k);
        if (i + 1 < M && j + 1 < N)
            find_solution(i + 1, j + 1, k);
        --k;
    }
    
    if (i + 1 < M)
        find_solution(i + 1, j, k);
    if (j + 1 < N)
    find_solution(i, j + 1, k);
}

int main()
{
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    read_data();
    find_solution(0, 0, -1);
    write_solution();

    return 0;
}
