#include <fstream>

#define MAXN 1027

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[MAXN], y[MAXN], dp[MAXN][MAXN], N, M;

void Read() {
    fin >> N >> M;

    for (int i = 1; i <= N; i++)
        fin >> x[i];
    for (int i = 1; i <= M; i++)
        fin >> y[i];
}

inline void Afis(int n, int m) {
    if (n && m) {
        if (x[n] == y[m])
            Afis(n - 1, m - 1),
            fout << x[n] << " ";
        else {
            if (dp[n - 1][m] > dp[n][m - 1])
                Afis(n - 1, m);
            else
                Afis(n, m - 1);
        }
    }
}

inline void cmlsc() {
    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= M; j++) {
            if (x[i] == y[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    fout << dp[N][M] << "\n";

    Afis(N, M);
}

int main () {
    Read();
    cmlsc();

    fin.close(); fout.close(); return 0;
}


