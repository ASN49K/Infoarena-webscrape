#include<bits/stdc++.h>

#define Nmax 1025

using namespace std;

int N, M, A[Nmax], B[Nmax], mat[Nmax][Nmax], Sol[Nmax], Sol_DIM;

void Read()
{
    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; ++ i)
        scanf("%d", &A[i]);
    for(int i = 1; i <= M; ++ i)
        scanf("%d", &B[i]);
}

void Write()
{
    freopen("cmlsc.out", "w", stdout);

    printf("%d\n", Sol_DIM);
    for( ; Sol_DIM; Sol_DIM --)
        printf("%d ", Sol[Sol_DIM]);
}

void Cmlsc()
{
    for(int i = 1; i <= N; printf("\n"), ++ i)
        for(int j = 1; j <= M; ++ j) {
            if(A[i] == B[j])
                mat[i][j] = mat[i - 1][j - 1] + 1;
            else
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            printf("%d ", mat[i][j]);
        }

    for(int i = N, j = M; i;) {
        if(A[i] == B[j]) {
            Sol[++Sol_DIM] = A[i];
            i --; j --;
            continue;
        }
        if(mat[i][j - 1] < mat[i - 1][j])
            i --;
        else
            j --;
    }

    Write();
}

int main()
{
    Read();
    Cmlsc();

    return 0;
}
