#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

const int maxn = 1030;
int A[maxn], B[maxn], Ans[maxn], Dp[maxn][maxn], lg;

int main() {
    ios_base :: sync_with_stdio(false);
    int n, m, i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++) {
        fin >> A[i];
    }
    for (i = 1; i <= m; i++) {
        fin >> B[i];
    }
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= m; j++) {
            if (A[i] == B[j]) {
                Dp[i][j] = Dp[i - 1][j - 1] + 1;
            } else {
                Dp[i][j] = max(Dp[i - 1][j], Dp[i][j - 1]);
            }
        }
    }
    i = n, j = m;
    while (i && j) {
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
    for (i = lg; i; i--) {
        fout << Ans[i] << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
