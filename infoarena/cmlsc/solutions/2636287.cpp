#include <fstream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int dp[1030][1030], a[1030], b[1030], n, m, sir[1030], best;

void citire() {
    fin >> m >> n;
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];
}

void solve() {
    for(int i = 1; i <= m; i++)
        for(int j = 1; j<= n; j++) {
            if(a[i] == b[j])
                dp[i][j] = dp[i-1][j-1] +1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    for(int i = m, j = n; i && j;) {
        if(a[i] == b[j]) {
            sir[++best] = a[i];
            i--, j--;
        } else if(dp[i-1][j] > dp[i][j-1])
            i--;
        else j--;
    }
}

void afis() {
    fout << best << '\n';
    for(int i = best; i > 0; i--)
        fout << sir[i] << ' ';
}

int main() {
    citire();
    solve();
    afis();
}
