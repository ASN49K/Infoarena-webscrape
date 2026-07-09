#include <fstream>
#include <algorithm>

using namespace std;

#define FIN "cmlsc.in"
#define FOUT "cmlsc.out"
#define MAX_N 1030

int N, M;
int A[MAX_N], B[MAX_N];
int D[MAX_N][MAX_N];

void read() {
    scanf("%d %d\n", &N, &M);
    for (int i = 1; i <= N; ++i)
        scanf("%d", &A[i]);
    for (int i = 1; i <= M; ++i)
        scanf("%d", &B[i]);
}

void print(int i, int j) {
    if (!i || !j) return;
    if (A[i] == B[j] && D[i - 1][j - 1] + 1 == D[i][j]) {
        print(i - 1, j - 1);
        printf("%d ", A[i]);
    } else if (D[i - 1][j] > D[i][j - 1])
        print(i - 1, j);
    else
        print(i, j - 1);
}

void solve() {
    for (int i = 1; i <= N; ++i)
        for (int j = 1; j <= M; ++j) {
            D[i][j] = max(D[i - 1][j], D[i][j - 1]);
            if (A[i] == B[j])
                D[i][j] = max(D[i][j], D[i - 1][j - 1] + 1);
        }
    printf("%d\n", D[N][M]);
    print(N, M);
}

int main() {
    freopen(FIN, "r", stdin);
    freopen(FOUT, "w", stdout);
    read();
    solve();
    return 0;
}
