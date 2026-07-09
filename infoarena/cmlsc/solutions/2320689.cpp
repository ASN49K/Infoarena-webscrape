#include <fstream>

#define MAXN 1026

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[MAXN][MAXN];
int x[MAXN], y[MAXN];

inline void Read(int &N, int &M) {
    fin >> N >> M;

    for (int i = 1; i <= N; i++)
        fin >> x[i];
    for (int i = 1; i <= M; i++)
        fin >> y[i];
}

inline void Dinamica(int N, int M) {
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            if (x[i] == y[j])
                a[i][j] = a[i - 1][j - 1] + 1;
            else
                a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    }
}

inline void Write(int N, int M) {
    fout << a[N][M] << "\n";

    int i = N, j = M;

    while (i >= 1 && j >= 1) {
        if (x[i] == y[j]) {
            fout << x[i] << " ";
            i -= 1; j -= 1;
        }
        else {
            if (a[i - 1][j] > a[i][j - 1]) {
                i -= 1;
            }
            else
                j -= 1;
        }
    }
}

int main () {
    int N, M;

    Read(N, M);
    Dinamica(N, M);
    Write(N, M);

    fin.close(); fout.close(); return 0;
}
