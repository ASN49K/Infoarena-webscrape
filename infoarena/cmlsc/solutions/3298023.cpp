#include <bits/stdc++.h>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int MAX_DIM = (1 << 10);

int d[MAX_DIM + 1][MAX_DIM + 1];
int a[MAX_DIM + 1], m;
int b[MAX_DIM + 1], n;

void bkt(int i, int j, int len) {
    if (len > 0) {
        if (a[i] == b[j]) {
            bkt(i - 1, j - 1, len - 1);
            g << a[i] << " ";
        } else {
            if (d[i - 1][j] > d[i][j - 1])
                bkt(i - 1, j, len);
            else
                bkt(i, j - 1, len);
        }
    }
}

int main() {
    f >> m >> n;
    for (int i = 1; i <= m; i++)
        f >> a[i];
    for (int j = 1; j <= n; j++)
        f >> b[j];
    
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i - 1][j - 1];
            else {
                if (d[i - 1][j] > d[i][j - 1])
                    d[i][j] = d[i - 1][j];
                else
                    d[i][j] = d[i][j - 1];
            }
            
    g << d[m][n] << "\n";
    bkt(m, n, d[m][n]);
    
    f.close();
    g.close();
    return 0;
}
