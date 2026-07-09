#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, v[1030], x[1030], dp[1030][1030], sol[1030], ind;

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; i++) {
        fin >> v[i];
    }
    for(int i = 1; i <= m; i++) {
        fin >> x[i];
    }
    fin.close();
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(v[i] == x[j]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    while(n > 0) {
        if(v[n] == x[m]) {
            sol[++ind] = v[n--];
            m--;
        } else {
            if(dp[n - 1][m] < dp[n][m - 1]) {
                m--;
            } else {
                n--;
            }
        }
    }
    fout << ind << "\n";
    for(int i = ind; i > 0; i--) {
        fout << sol[i] << " ";
    }
    fout.close();
    return 0;
}