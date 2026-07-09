#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    ifstream fin("cmlsc.in");
    if (!fin.is_open()) {
        cout << "The file can't be opened!\n";
        exit(EXIT_FAILURE);
    }

    int n, m;
    fin >> n >> m;
    int *a = new int[n + 1];
    int *b = new int[m + 1];

    for (int i = 1; i <= n; ++i) {
        fin >> a[i];
    }

    for (int i = 1; i <= m; ++i) {
        fin >> b[i];
    }
    // close the file
    fin.close();

    // solve
    int **d = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        d[i] = new int[m + 1];
        for (int j = 0; j <= m; ++j) {
            d[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else
                d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }

    ofstream cout("cmlsc.out");

    cout << d[n][m] << '\n';

    int pos1 = n, pos2 = m;
    int k = 0;
    int *sol = new int[d[n][m] + 1];
    while (pos1 >= 1 && pos2 >= 1) {
        if (d[pos1][pos2] == d[pos1 - 1][pos2])
            pos1 -= 1;
        else if (d[pos1][pos2] == d[pos1][pos2 - 1])
            pos2 -= 1;
        else if (d[pos1][pos2] == d[pos1 - 1][pos2 - 1] + 1) {
            sol[k++] = a[pos1];
            pos1--;
            pos2--;
        }
    }

    for (int i = k - 1; i >= 0; --i)
        cout << sol[i] << ' ';

    // free up memeory
    free(a);
    free(b);
    free(sol);
    return 0;
}