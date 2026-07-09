#include <bits/stdc++.h>
#define mod 9901

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, j, d[1027][1027];
int a[1027], b[1027], v[1027];
stack<int> r;

int main() {
    fin >> n >> m;
    for(int i = 1; i <= n; i++) fin >> a[i];
    for(int j = 1; j <= m; j++) fin >> b[j];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i] == b[j]) d[i][j] = d[i - 1][j - 1] + 1;
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    fout << d[n][m] << "\n";
    int i = n;
    int j = m;
    while(i && j) {
        if(a[i] == b[j]) {
            r.push(a[i]);
            i--;
            j--;
        }
        else if(d[i - 1][j] > d[i][j - 1]) i--;
        else j--;
    }
    while(!r.empty()) {
        fout << r.top() << " ";
        r.pop();
    }

    return 0;
}
