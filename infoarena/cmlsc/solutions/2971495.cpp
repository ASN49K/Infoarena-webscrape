#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j;
int a[1026], b[1026], x[1026][1026], r[1026];

int main() {
    ios_base::sync_with_stdio(false);
    fin.tie(NULL);
    fin >> n >> m;
    for(i = 1; i <= n; i++) fin >> a[i];
    for(i = 1; i <= m; i++) fin >> b[i];
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(a[i] == b[j]) x[i][j] = x[i - 1][j - 1] + 1;
            else x[i][j] = max(x[i - 1][j], x[i][j - 1]);
        }
    }
    i = n;
    j = m;
    while(i && j) {
        if(a[i] == b[j]) {
            r[++r[0]] = a[i];
            i--;
            j--;
        }
        else if(x[i - 1][j] < x[i][j - 1]) j--;
        else i--;
    }
    fout << r[0] << "\n";
    while(r[0]) fout << r[r[0]--] << " ";

    return 0;

}
