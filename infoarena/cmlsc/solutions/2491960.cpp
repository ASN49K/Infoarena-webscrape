#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

const int NMAX = 1025;

int M, N;
short C[NMAX][NMAX],
      A[NMAX], B[NMAX], S[NMAX];

void calc() {
    for(int i = 1; i <= M; i++)
        for(int j = 1; j <= N; j++)
            if(A[i] == B[j])
                C[i][j] = C[i-1][j-1] + 1;
            else C[i][j] = max(C[i-1][j], C[i][j-1]);
}

void gen_1() {
    int i = M, j = N, k = C[M][N];
    while(i > 0 && j > 0)
        if(A[i] == B[j]) {
            S[k] = A[i];
            i--, j--, k--;
        } else if(C[i-1][j] >= C[i][j-1])
            i--;
        else j--;
}

void gen_2(int i, int j) {
    if(i >= 1 && j >= 1)
        if(A[i] == B[j]) {
            gen_2(i, j-1);
            out << A[i] << ' ';
        } else if(C[i-1][j] >= C[i][j-1])
            gen_2(i-1, j);
        else gen_2(i, j-1);
}

int main() {
    in >> M >> N;
    for(int i = 1; i <= M; i++)
        in >> A[i];
    for(int i = 1; i <= N; i++)
        in >> B[i];

    calc();

    out << C[M][N] << '\n';
    gen_2(M, N);
    return 0;
}