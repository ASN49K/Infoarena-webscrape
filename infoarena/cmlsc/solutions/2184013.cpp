#include <bits/stdc++.h>
using namespace std;
     
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int DP[1025][1025], a[1025], b[1025];

int main() {
    ios::sync_with_stdio(false); in.tie(0); out.tie(0);

    int n, m; in >> n >> m;

    for(int i = 1; i <= n; ++i) {
        in >> a[i];
    }
    for(int i = 1; i <= m; ++i) {
        in >> b[i];
    }

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]) + (a[j] == b[i]);
        }
    }

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            out << DP[i][j] << " ";
        }
        out << '\n';
    }

    out << DP[m][n] << '\n';
    vector< int > sol;

    int i = m, j = n;
    while(i >= 1 && j >= 1) {
        if(DP[i][j] == max(DP[i - 1][j], DP[i][j - 1]) + 1) {
            sol.push_back(a[j]);
            i--;
        }
        if(DP[i - 1][j] > DP[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    reverse(sol.begin(), sol.end());

    for(auto x: sol) out << x << " ";

    in.close(); out.close();
     
    return 0;
}