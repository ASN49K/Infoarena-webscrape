#include <iostream>
#include <fstream>
using namespace std;

ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");

const int NMAX = 1024;

int M, N, A[NMAX+1], B[NMAX+1],
    C[NMAX+1][NMAX+1], S[NMAX+1];

void citire() {
    f >> M >> N;
    for (int i=1; i<=M; i++)
        f >> A[i];
    for (int i=1; i<=N; i++)
        f >> B[i];
}

void calcul() {
    for (int i=1; i<=M; i++)
        for (int j=1; j<=N; j++)
            if (A[i] == B[j])
                C[i][j] = C[i-1][j-1] + 1;
            else
                C[i][j] = max(C[i-1][j], C[i][j-1]);
}

void generare() {
    int i = M, j = N, k = C[M][N];
    while(i > 0 && j > 0) {
        if (A[i] == B[j]) {
            S[k] = A[i];
            i--, j--, k--;
        } else
            if (C[i-1][j] >= C[i][j-1])
                i--;
            else
                j--;
    }
}

void afisare() {
    int MAX = C[M][N];
    g << MAX << '\n';
    for (int i=1; i<=MAX; i++)
        g << S[i] << ' ';
}

int main()
{
    citire();
    calcul();
    generare();
    afisare();
    g.close();
    f.close();
    return 0;
}
