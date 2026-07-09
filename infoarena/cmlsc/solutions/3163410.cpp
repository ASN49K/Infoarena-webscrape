#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int c[1024][1024];
int lcs(int n, int m, int v1[], int v2[]) {
    for (int i = 0; i < m; i++) c[i][0] = 0;
    for (int i = 0; i < n; i++) c[0][i] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (v1[i] == v2[j]) c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }

    return c[n][m];
}

vector<int> rez;
void back(int v1[], int v2[], int i, int j) {
    if (i == 0 || j == 0) return;

    if (v1[i] == v2[j]) {
        back(v1, v2, i - 1, j - 1);
        rez.push_back(v1[i]);
    }
    if (c[i][j - 1] > c[i - 1][j]) {
        back(v1, v2, i, j - 1);
    }
    else {
        back(v1, v2, i - 1, j);
    }
}

int main() {
    int a[1024], b[1024];
    int n, m, x;
    fin>>n>>m;
    for (int i = 1; i <= n; i++) {
        fin>>x;
        a[i] = x;
    }
    for (int i = 1; i <= m; i++) {
        fin>>x;
        b[i] = x;
    }

    int k = lcs(n, m, a, b);
    back(a, b, n, m);

    fout<<k<<endl;
    for (int i = k; i > 0; i--) fout<<rez[i]<<" ";
    return 0;
}
