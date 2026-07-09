#include <fstream>
#include <cstring>
#include <algorithm>
using namespace std;

ifstream fin("codul.in");
ofstream fout("codul.out");

const int MAXN = 1050;
string s;
int n, m;
int v[MAXN], a[MAXN];
int c[MAXN][MAXN];
int sol[MAXN];

int main() {

    fin >> s;
    n = s.size();
    for (int i = 0; i < n; ++i) {
        v[i + 1] = s[i] - '0';
    }
    fin >> s;
    m = s.size();
    for (int i = 0; i < m; ++i) {
        a[i + 1] = s[i] - '0';
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i] == a[j]) {
                c[i][j] = c[i - 1][j - 1] + 1;
            }
            else {
                c[i][j] = max(c[i - 1][j], c[i][j - 1]);
            }
        }
    }
    int cr = c[n][m];
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (v[i] == a[j]) {
                sol[c[i][j]] = max(sol[c[i][j]], v[i]);
            }
        }
    }
    for (int i = 1; i <= cr; ++i) {
        fout << sol[i];
    }


    fout.close();
    return 0;
}
