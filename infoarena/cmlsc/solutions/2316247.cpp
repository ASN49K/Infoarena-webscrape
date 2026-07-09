#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void read(int &n, int &m, int **a, int **b) {
    ifstream fin("cmlsc.in");
    if (!fin.is_open()) {
        cout << "The file can't be opened!\n";
        exit(EXIT_FAILURE);
    }

    fin >> n >> m;
    *a = new int[n + 1];
    *b = new int[m + 1];

    for (int i = 1; i <= n; ++i) {
        fin >> (*a)[i];
    }

    for (int i = 1; i <= m; ++i) {
        fin >> (*b)[i];
    }
    fin.close();
}


int main() {
    int n, m, *a, *b;
    read(n, m, &a, &b);
    int **d = new int*[n + 1];
    for (int i = 0; i <= n; ++i) {
        d[i] = new int[m + 1];
        for (int j = 0; j <= m; ++j)
            d[i][j] = 0;
    }
    //
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            d[i][j] = max(d[i - 1][j], d[i][j - 1]);
            if (a[i] == b[j])
                d[i][j] = max(d[i][j], d[i - 1][j - 1] + 1);
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }

    int aux = d[n][m];
    int pos1 = n, pos2 = m;
    int dim = 0;
    int *sol = new int[max(n, m)];
    while (pos1 >= 1 && pos2 >= 1) {
        if (d[pos1 - 1][pos2] == d[pos1][pos2])
            --pos1;
        else if (d[pos1][pos2 - 1] == d[pos1][pos2])
            --pos2;
        else if (d[pos1][pos2] == d[pos1 - 1][pos2 - 1] + 1) {
            sol[dim++] = a[pos1];
            --pos1;
            --pos2;
        }
    }

    ofstream fout("cmlsc.out");
    fout << dim << '\n';
    for (int i = dim - 1; i >= 0; --i) {
        fout << sol[i] << ' ';
    }
    return 0;
}