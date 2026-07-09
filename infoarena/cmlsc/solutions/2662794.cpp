#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1050], b[1050];
int d[1050][1050];

void drum(int i, int j, int k) {
    if (k != 0)
        if (a[i] == b[j]) {
            drum(i - 1, j - 1, k - 1);
            fout << a[i] << " ";
        } else
            if (d[i-1][j] > d[i][j-1])
                drum(i-1, j, k);
            else
                drum(i, j-1, k);
}

int main() {
    fin >> n >> m;

    for (int i=1;i<=n;++i)
        fin >> a[i];

    for (int i=1;i<=m;++i)
        fin >> b[i];

    for (int i=1;i<=n;++i)
        for (int j=1;j<=m;++j)
            if (a[i] == b[j])
                d[i][j] = d[i-1][j-1] + 1;
            else
                d[i][j] = max(d[i][j-1], d[i-1][j]);

    fout << d[n][m] << "\n";

    drum(n, m, d[n][m]);
}
