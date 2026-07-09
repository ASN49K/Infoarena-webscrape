#include <fstream>
using namespace std;

ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");

/**
 *        NULL                                         i = 0 or j = 0
 * LCS =  LCS(X(i-1), Y(i-1))                          i, j > 0 and x(i) = y(i)
 *        max(LCS(X(i), Y(i-1)), LCS(X(i-1), Y(i)))    i, j > 0 and x(i) != y(i)
 */

void read(int& n, int a[], int& m, int b[]) {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
}

int LCS(int i, int j, int n, const int a[], int m, const int b[], int k, int c[]) {
    if (i == -1 || j == -1) {
        return 0;
    }

    if (a[i] == b[j]) {
        c[k--] = a[i];
        return 1 + LCS(i - 1, j - 1, n, a, m, b, k, c);
    }

    int var1 = LCS(i - 1, j, n, a, m, b, k, c);
    int var2 = LCS(i, j - 1, n, a, m, b, k, c);

    return (var1 > var2) ? var1 : var2;
}

void write(int start, int finish, const int a[]) {
    for (int i = start; i < finish; ++i)
        cout << a[i] << ' ';
}

int main() {
    int n, m, k;
    int a[1030] = {0}, b[1030] = {0}, c[1030] = {0};

    read(n, a, m, b);
    k = (n > m) ? n : m;

    int len = LCS(n - 1, m - 1, n, a, m, b, k - 1, c);

    cout << len << '\n';
    write(k - len, k, c);

    return 0;
}