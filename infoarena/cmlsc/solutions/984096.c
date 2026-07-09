#include <stdio.h>
#define MAXSIZE 1025
#define MAX(x, y) ((x) > (y) ? (x) : (y))

int N, M;
int A[MAXSIZE], B[MAXSIZE];
int S[MAXSIZE][MAXSIZE];

void print_solution(int i, int j)
{
    if (i > 0 && j > 0)
    {
        if (A[i] == B[j])
        {   
            print_solution(i-1, j-1);
            printf("%d ", A[i]);
        } 
        else if (S[i-1][j] > S[i][j-1])
        {
            print_solution(i-1, j);
        }
        else
        {
            print_solution(i, j-1);
        }
    }
}

int main()
{
    int i, j;
    freopen("cmlsc.in", "r", stdin);    
    freopen("cmlsc.out", "w", stdout);    
    
    scanf("%d %d", &M, &N);
    
    // read data
    for (i = 1; i <= M; ++i)
        scanf("%d", &A[i]);
    for (i = 1; i <= N; ++i)
        scanf("%d", &B[i]);

    // init the matrix that stores the solution
    for (i = 0; i <= M; ++i)    
        S[i][0] = 0;
    for (j = 0; j <= N; ++j)
        S[0][j] = 0;

    // compute the solution
    for (i = 1; i <= M; ++i)
        for (j = 1; j <= N; ++j)
            if (A[i] == B[j])
                S[i][j] = 1 + S[i-1][j-1];
            else 
                S[i][j] = MAX(S[i-1][j], S[i][j-1]);

    // print the length
    printf("%d\n", S[M][N]);

    print_solution(M, N);

    return 0;
}
