#include <iostream>
#include <fstream>

using namespace std;

const int NMAX = 1025;

int A[NMAX], B[NMAX], matched[NMAX];
int dp[NMAX][NMAX];

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int max(int x, int y, int z) {
    if (x > y && x > z) {
        return x;
    }
    if (y > x && y > z) {
        return y;
    }
    return z;
}

int main()
{
    int m, n, i, j, best;

    fin >> m >> n;
    for(i = 1; i <= m; i++)
        fin >> A[i];
    for(i = 1; i <= n; i++)
        fin >> B[i];

    for(i = 1; i <= m; i++) {
        for(j = 1; j <= n; j++) {
            if (A[i] == B[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    best = 0;
    i = m, j = n;
    while(i > 0 && j > 0) {
        if (A[i] == B[j]) {
            matched[best++] = A[i];
            i--, j--;
        } else if (dp[i][j - 1] > dp[i - 1][j]) {
            j--;
        } else {
            i--;
        }
    }

    fout << best << "\n";
    best--;
    while(best >= 0) {
        fout << matched[best] << " ";
        best--;
    }
    return 0;
}