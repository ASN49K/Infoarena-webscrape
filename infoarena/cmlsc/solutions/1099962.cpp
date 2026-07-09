#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXL = 1025;
int dx[] = {0, -1, -1};//left, upper-left, up;
int dy[] = {-1, -1, 0};
int dir[MAXL][MAXL];
int LCS[MAXL][MAXL];
int N, M;
int A[MAXL], B[MAXL];

void Read() {
    fin >> M >> N;
    for (int i = 1; i <= M; ++i)
        fin >> A[i];
    for (int i = 1; i <= N; ++i)
        fin >> B[i];
}

void Solve() {
    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (A[i] == B[j]) {
                LCS[i][j] = 1 + LCS[i - 1][j - 1];
                dir[i][j] = 1;
            }else {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
                if (LCS[i - 1][j] > LCS[i][j - 1])
                    dir[i][j] = 2;//up
                else
                    dir[i][j] = 0;//left
            }
        }
    }
}

void Rec(int i, int j) {
    if (i && j) {//when we get to the first row or column, we stop
        Rec(i + dx[dir[i][j]], j + dy[dir[i][j]]);
        if (A[i] == B[j])
            fout << A[i] << ' ';
    }
}

int main() {
    Read();
    Solve();
    fout << LCS[M][N] << '\n';
    Rec(M, N);
    fin.close();
    fout.close();
    return 0;
}
