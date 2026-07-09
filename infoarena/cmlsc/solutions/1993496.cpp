#include <iostream>
#include <fstream>

using namespace std;

#define NMAX 1024
#define maxim(a, b) ((a > b) ? a : b)

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int D[NMAX][NMAX];

int main() {
    int N, M, A[NMAX], B[NMAX], S[NMAX], len = 0;

    in >> M >> N;

    for (int i = 1; i <= M; i++)
        in >> A[i];

    for (int j = 1; j <= N; j++)
        in >> B[j];

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            if (A[i] == B[j])
                D[i][j] = 1 + D[i - 1][j - 1];
            else
                D[i][j] = maxim(D[i - 1][j], D[i][j - 1]);

    int i = M, j = N;

    while (i) {
        if (A[i] == B[j]) {
            S[++len] = A[i];
            --i;
            --j;
        } else if (D[i - 1][j] < D[i][j - 1])
            --j;
        else
            --i;
    }
    out << D[M][N] << '\n';
    for (i = len; i > 0; i--)
        out << S[i] << " ";

    in.close();
    out.close();
}

