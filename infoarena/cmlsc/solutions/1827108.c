#include <stdio.h>
#include <stdlib.h>

#define NMAX 260

int N, M;
int dim;
int A[NMAX], B[NMAX];
int subsir[NMAX];
int solutie[NMAX];

int substring(int nr)
{
    int i = 1;
    int j = 1;

    while(i <= nr && j <= N)
    {
        while(j <= N && B[j] != subsir[i])
            j ++;
        i ++;
    }

    return j <= N;
}

void backtracking(int nivel, int lungime)
{
    int i;

    if(nivel == N+1)
    {
        if(substring(lungime))
            if(lungime > dim)
            {
                dim = lungime;
                for(i = 1; i <= dim; i ++)
                    solutie[i] = subsir[i];
            }

        return ;
    }

    backtracking(nivel+1, lungime);

    subsir[lungime+1] = A[nivel];

    backtracking(nivel+1, lungime+1);
}

int main()
{
    int i;

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d", &N);
    scanf("%d", &M);
    for(i = 1; i <= N; i ++)
        scanf("%d", &A[i]);
    for(i = 1; i <= M; i ++)
        scanf("%d", &B[i]);

    backtracking(1,0);

    printf("%d\n", dim);
    for(i = 1; i <= dim; i ++)
        printf("%d ", solutie[i]);

    return 0;
}
