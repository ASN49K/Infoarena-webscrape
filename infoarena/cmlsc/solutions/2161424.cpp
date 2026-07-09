#include <iostream>
#include <fstream>
#include <algorithm>

void solution (const int a[], int m, const int b[], int n, std::ofstream& out) {

    int i, j;
    int x[m + 1][n + 1];

    for (i = 0; i <= m; ++i) {
        x[i][0] = 0;
    }
    for (j = 0; j <= n; ++j) {
        x[0][j] = 0;
    }

    for (i = 1; i <= m; ++i) {
        for (j = 1; j <=n; ++j) {
            if (a[i - 1] == b[j - 1]) {
                x[i][j] = x[i - 1][j - 1] + 1;
            } else {
                x[i][j] = std::max(x[i - 1][j], x[i][j - 1]);
            }
            std::cout << x[i][j] << ' ';
        }
        std::cout << '\n';
    }

    out << x[m][n] << '\n';

    int solution[x[m][n]];
    i = 0;

    while (m != 0 && n != 0) {
        if (x[m][n] == x[m - 1][n - 1] + 1) {
            solution[i] = b[n - 1];
            ++i;
            --m;
            --n;
        } else if (x[m][n] == x[m][n - 1]) {
            --n;
        } else {
            --m;
        }
    }

    for (j = i; j > 0; --j) {
        out << solution[j - 1] << ' ';
    }

}

int main() {

    std::ifstream in;
    std::ofstream out;
    in.open("cmlsc.in");
    out.open("cmlsc.out");

    int m, n, i;
    in >> m >> n;

    int a[m], b[n];

    for (i = 0; i < m; ++i) {
        in >> a[i];
    }

    for (i = 0; i < n; ++i) {
        in >> b[i];
    }

    solution(a, m, b, n, out);

    in.close();
    out.close();

    return 0;

}