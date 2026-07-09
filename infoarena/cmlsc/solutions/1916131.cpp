#include <fstream>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1050;
int n, m;
int v[MAXN], a[MAXN];
int c[MAXN][MAXN];

int main() {

    fin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        fin >> v[i];
    }
    for (int i = 1; i <= m; ++i) {
        fin >> a[i];
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
    fout << c[n][m] << '\n';
    stack<int> q;
    for (int i = n, j = m; i >= 1 && j >= 1; ) {
        if (v[i] == a[j]) {
            q.push(v[i]);
            i--;
            j--;
        }
        else if (c[i - 1][j] > c[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }
    while (!q.empty()) {
        fout << q.top() << ' ';
        q.pop();
    }

    fout.close();
    return 0;
}
