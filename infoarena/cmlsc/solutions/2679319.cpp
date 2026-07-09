#include <stdio.h>

#define NMax 260

int M, N, A[NMax], B[NMax], subsir[NMax], LunSol, sol[NMax];

int verifsubsir(int nr) // daca subsir[1..nr] este subsir pentru B[1..N]
{
    int i, j = 1;
    for (i = 1; i <= nr && j <= N; i++)
      while (j <= N && B[j] != subsir[i]) ++j;
    return j <= N;
}

void back(int indice, int len)
{
    int i;

    if (indice == M+1)
    {
        if (verifsubsir(len)) // daca subsir[] este subsir si pentru B
            if (len > LunSol)
            {
                LunSol = len;
                for (i = 1; i <= LunSol; i++)
                    sol[i] = subsir[i];
            }

        return ;
    }

    // nu folosim A[indice] in cmlsc
    back(indice+1, len);
    // folosim A[indice] in solutie
    subsir[len+1] = A[indice];
    back(indice+1, len+1);
}

int main(void)
{
    int i;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    //primul sir
    for (i = 1; i <= M; i++)
        scanf("%d", &A[i]);
    //al doilea sir
    for (i = 1; i <= N; i++)
        scanf("%d", &B[i]);

    back(1, 0);

    printf("%d\n", LunSol);
    for (i = 1; i < LunSol; i++)
        printf("%d ", sol[i]);
    printf("%d\n", sol[LunSol]);

    return 0;
}
