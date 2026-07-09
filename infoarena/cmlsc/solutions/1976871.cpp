#include <bits/stdc++.h>
using namespace std;

#define NMAX 1026

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int A[NMAX], B[NMAX];
int D[NMAX][NMAX];

void LCS(const int N, const int M) {

    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j)
            if (A[i] == B[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);

    fout << D[N][M] << "\n";


    int i = N, j = M, ind = D[N][M];

    vector<int> Sol(ind + 1);

    while (i > 0 && j > 0) {

        if (A[i] == B[j]) {

            Sol[ind--] = A[i];

            i--;
            j--;

            continue;
        }

        if (D[i - 1][j] > D[i][j - 1])
            i--;
        else
            j--;
    }

    for (int i = 1; i <= D[N][M]; ++i)
        fout << Sol[i] << " ";
}

int main() {

    int N, M;

    fin >> N >> M;

    for (int i = 1; i <= N; ++i)
        fin >> A[i];

    for (int i = 1; i <= M; ++i)
        fin >> B[i];

    LCS(N, M);

    return 0;
}
