#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int maxn = 1025;
int Dp[maxn][maxn], A[maxn], B[maxn], Ans[maxn];
int n, m, lg;

int main() {
    ios_base :: sync_with_stdio(false);
    fin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fin >> A[i];
    }
    for (int i = 1; i <= m; i++) {
        fin >> B[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                Dp[i][j] = Dp[i - 1][j - 1] + 1;
            } else {
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
            }
        }
    }
    int i = n;
    int j = m;
    while (i > 0 && j > 0) {
        if (A[i] == B[j]) {
            Ans[++lg] = A[i];
            i--;
            j--;
        } else if (Dp[i - 1][j] > Dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    fout << lg << "\n";
    for (i = lg; i > 0; i--) {
        fout << Ans[i] << " ";
    }
    fout << "\n";
    return 0;
}
