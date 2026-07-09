#include <fstream>

using namespace std;

const int MAX_N = 1024;

int A[MAX_N + 1], B[MAX_N + 1];
int D[MAX_N + 1][MAX_N + 1];

void redo(int N, int M, ofstream &fout) {
    if (!N || !M) {
        return;
    }
    if (A[N] == B[M]) {
        redo(N - 1, M - 1, fout);
        fout << A[N] << ' ';
    } else {
        if (D[N - 1][M] > D[N][M - 1]) {
            redo(N - 1, M, fout);
        } else {
            redo(N, M - 1, fout);
        }
    }
}

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin.tie(0);
    ios_base::sync_with_stdio(false);

    int N, M; fin >> N >> M;

    for (int i = 1; i <= N; ++ i)
        fin >> A[i];

    for (int i = 1; i <= M; ++ i)
        fin >> B[i];

    for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= M; ++ j) {
            if (A[i] == B[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }

    fout << D[N][M] << '\n';
    redo(N, M, fout); fout << '\n';
    fout.close();

    return 0;
}
