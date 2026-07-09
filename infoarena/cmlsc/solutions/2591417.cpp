#include <iostream>
#include <fstream>
#define maxdim 1024
#define Max(a, b) ((a > b) ? a : b)

std ::ifstream in("cmlsc.in");
std :: ofstream out("cmlsc.out");

int N, M, i, j, A[maxdim], B[maxdim], d[maxdim][maxdim], solution[maxdim], solPos = -1;

int main() {

    in >> M >> N;

    for (i = 0; i < M; i += 1)
        in >> A[i];
    for (i = 0; i < N; i += 1)
        in >> B[i];

    for (i = 1; i <= M; i += 1)
    for (j = 1; j <= N; j += 1) {
        if (A[i - 1] == B[j - 1])
            d[i][j] = 1 + d[i-1][j-1];
        else
            d[i][j] = Max(d[i-1][j], d[i][j-1]);
    }

    for (i = M, j = N; i;) {
        if (A[i - 1] == B[j - 1])
            solution[++solPos] = A[i - 1], --i, --j;
        else if (d[i - 1][j] > d[i][j - 1])
            --i;
        else
            --j;
    }

    out << d[M][N] << "\n";

    for (int i = solPos; i >= 0; --i)
        out<<solution[i]<<" ";

    return 0;

}
