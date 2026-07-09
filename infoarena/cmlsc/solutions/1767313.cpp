#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> AflaSubsir(const vector<int> &a, const vector<int> &b)
{
    int n = a.size() - 1;
    int m = b.size() - 1;
    vector<vector<int>> lung(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i] == b[j])
                lung[i][j] = lung[i - 1][j - 1] + 1;
            else lung[i][j] = max(lung[i][j - 1], lung[i - 1][j]);
        }
    }

    vector<int> subsir(lung[n][m]);
    int index = lung[n][m];
    int x = n, y = m;

    while (x > 0 && y > 0) {
        if (a[x] == b[y]) {
            subsir[--index] = a[x];
            --x;
            --y;
        } else if (lung[x - 1][y] > lung[x][y - 1]) {
            --x;
        } else {
            --y;
        }
    }

    return subsir;
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");

    int n, m;
    fin >> n >> m;

    vector<int> a(n + 1);
    while (n--) fin >> a[a.size() - n - 1];

    vector<int> b(m + 1);
    while (m--) fin >> b[b.size() - m - 1];

    auto subsir = AflaSubsir(a, b);
    fout << subsir.size() << "\n";
    for (int i : subsir)
        fout << i << " ";

    return 0;
}
