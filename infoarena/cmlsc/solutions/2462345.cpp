#include <iostream>
#include <fstream>
#include <algorithm>
#include <stack>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

const int MAXN = 1e3;
int a[MAXN + 50], b[MAXN + 50], matrix[MAXN + 50][MAXN + 50], n, m;
stack<int> sol;

void read() {
    fin >> n >> m;
    for (int i = 1; i <= n; ++i)
        fin >> a[i];
    for (int i = 1; i <= m; ++i)
        fin >> b[i];
}

void solve() {
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            if (a[i] == b[j])
                matrix[i][j] = max(matrix[i][j], matrix[i - 1][j - 1] + 1);
        }
}

void createSol() {
    for (int i = n, j = m; matrix[i][j] > 0; --i, --j) {
        while (a[i] != b[j]) {
            if (matrix[i][j] == matrix[i - 1][j])
                --i;
            if (matrix[i][j] == matrix[i][j - 1])
                --j;
        }
        sol.push(a[i]);
    }
}

void print() {
    fout << matrix[n][m] << '\n';
    while (!sol.empty()) {
        fout << sol.top() << ' ';
        sol.pop();
    }
}

int main() {
    read();
    solve();
    createSol();
    print();
    return 0;
}
