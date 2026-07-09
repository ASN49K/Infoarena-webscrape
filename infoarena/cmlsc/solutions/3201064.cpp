#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int x[1025], y[1025];
int lcs_matrix[2025][2025];

void build_lcs_matrix (int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (x[i] == y[j]) {
                lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1;
            }
            else {
                lcs_matrix[i][j] = max(lcs_matrix[i - 1][j], lcs_matrix[i][j - 1]);
            }
        }
    }
}

void display_lcs (int n, int m) {
    int i = n, j = m, k = 1;
    int lcs[2025];
    while (i >= 1 && j >= 1) {
        if (x[i] == y[j]) {
            lcs[k++] = x[i];
            i--;
            j--;
        }
        else {
            if (lcs_matrix[i][j - 1] > lcs_matrix[i - 1][j]) j--;
            else i--;
        }
    }
    k--;
    fout<<k<<endl;
    for (i = k; i >= 1; i--) fout<<lcs[i]<<" ";
}

int main() {
    int n, m;
    fin>>n>>m;
    for (int i = 1; i <= n; i++) fin>>x[i];
    for (int i = 1; i <= m; i++) fin>>y[i];

    build_lcs_matrix(n, m);
    display_lcs(n, m);

    return 0;
}