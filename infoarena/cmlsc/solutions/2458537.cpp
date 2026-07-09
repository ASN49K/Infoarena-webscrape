#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

short mp[1030][1030], v[1030], w[1030], n, m, i, j;

void f(int i, int j) {
    if(mp[i][j] == 0) return;
    if(w[i] == v[j]) {
        f(i-1, j-1);
        (fout << w[i]).put(' ');
    } else {
        if(mp[i-1][j] > mp[i][j-1]) f(i-1, j);
        else f(i, j-1);
    }
}

int main() {
    fin >> n >> m;
    for(i = 1; i <= n; ++i)
        fin >> v[i];
    for(i = 1; i <= m; ++i) {
        fin >> w[i];
        for(j = 1; j <= n; ++j)
            mp[i][j] = (w[i] == v[j] ? mp[i-1][j-1] + 1 : max(mp[i-1][j], mp[i][j-1]));
    }
    (fout << mp[m][n]).put('\n');
    f(m, n);
    return 0;
}