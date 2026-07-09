#include <bits/stdc++.h>
#define NMAX 1100

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n, A[NMAX][NMAX], M[NMAX], N[NMAX];

void findSequence(int i, int j) {
    if(i == 0 || j == 0) return;
    if(N[i] == M[j]) {
        findSequence(i - 1, j - 1);
        fout << N[i] << ' ';
    } else {
        if(A[i - 1][j] > A[i][j - 1]) {
            findSequence(i - 1, j);
        } else {
            findSequence(i, j - 1);
        }
    }
}

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> N[i];
    for(int i = 1; i <= m; i++)
        fin >> M[i];

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(N[i] == M[j]) {
                A[i][j] = A[i - 1][j - 1] + 1;
            }
            else {
                A[i][j] = max(A[i - 1][j], A[i][j - 1]);
            }
        }
    }
    fout << A[n][m] << '\n';
    findSequence(n, m);
    return 0;
}
