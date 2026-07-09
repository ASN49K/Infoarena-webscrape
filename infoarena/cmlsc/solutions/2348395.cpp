#include <fstream>

#define NMax 1030
#define Max(a, b) (a > b) ? a : b

using namespace std;

int M, N;
int D[NMax][NMax], s1[NMax], s2[NMax], sol[NMax];

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int main() {


    in >> M >> N;

    for (int i = 1; i <= M; ++i) {
        in >> s1[i];
    }
    for (int i = 1; i <= N; ++i) {
        in >> s2[i];
    }

    for (int i = 1; i <= M; ++i) {
        for (int j = 1; j <= N; ++j) {
            if (s1[i] == s2[j]) {
                D[i][j] = D[i - 1][j - 1] + 1;
            } else {
               D[i][j] = Max(D[i - 1][j], D[i][j - 1]);
            }
        }
    }

    out << D[M][N] << '\n';

    int i = M, j = N, k = 0;

    while (i) {
        if (s1[i] == s2[j]) {
            sol[k++] = s1[i];
            --i;
            --j;
        } else if (D[i - 1][j] < D[i][j - 1]) {
            --j;
        } else {
            --i;
        }
    }
    for (i = k - 1; i >= 0; --i) {
        out << sol[i] << ' ';
    }
    out << '\n';

    return 0;
}