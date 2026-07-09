
#include <stdio.h>

#define NMax 260

int M, N, A[NMax], B[NMax], sir[NMax], bst, sol[NMax];

int subsir(int nr) // daca sir[1..nr] este subsir pentru B[1..N]
{
    int i, j = 1;

    for (i = 1; i <= nr && j <= N; i++)
        for (; j <= N && B[j] != sir[i]; ++j);
    return j <= N;
}

bool back(int nivel, int len)
{
    int i;

    if (nivel == M+1)
    {
        if (subsir(len))  {// daca sir este subsir si pentru B
            if (len > bst)
            {
                bst = len;
                for (i = 1; i <= bst; i++)
                    sol[i] = sir[i];
            }
            if (bst >= (N > M ? M : N))
                return true;
        }

        return false;
    }

    sir[len+1] = A[nivel];
    if(back(nivel+1, len+1)) {
        return true;
    }

    return back(nivel+1, len);
}

int main(void)
{
    int i;

    freopen("cmlsc.in", "r", stdin);
    freopen("cmlsc.out", "w", stdout);

    scanf("%d %d", &M, &N);
    for (i = 1; i <= M; i++)
        scanf("%d", &A[i]);
    for (i = 1; i <= N; i++)
        scanf("%d", &B[i]);

    back(1, 0);

    printf("%d\n", bst);
    for (i = 1; i < bst; i++)
        printf("%d ", sol[i]);
    printf("%d\n", sol[bst]);

    return 0;
}
