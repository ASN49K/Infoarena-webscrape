#include <iostream>
#include <cstdio>
using namespace std;

#define Nmax 1024

int N, M, l;

int A[Nmax], B[Nmax], C[Nmax], L[Nmax][Nmax];

void citire(){

    freopen("cmlsc.in", "r", stdin);

    scanf("%d %d", &N, &M);

    for(int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);

    for(int i = 1; i <= M; ++i)
        scanf("%d", &B[i]);
}

void dinamica(){

    for(int i = 1; i <= N; i++)
        for(int j = 1; j <= M; j++)
            if(A[i] == B[j])
                L[i][j] = L[i-1][j-1] + 1;
            else
                L[i][j] = max( L[i-1][j], L[i][j-1] );
}

void construieste(){

    for(int i = N, j = M; i; )
        if(A[i] == B[j])
            C[++l] = A[i],
            i--,
            j--;
        else
            if(L[i-1][j] < L[i][j-1])
                j--;
            else
                i--;
}

void afis(){

    freopen("cmlsc.out", "w", stdout);

    printf("%d\n", l);

    for(int i = l; i > 0; i--)
        printf("%d ", C[i]);
}


int main(){

    citire();
    dinamica();
    construieste();
    afis();

    return 0;
}
