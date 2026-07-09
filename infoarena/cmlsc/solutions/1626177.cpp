#include <bits/stdc++.h>

using namespace std;

const int N_MAX = 1024 + 1;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m, n;
int a[N_MAX], b[N_MAX];
int cmlsc[N_MAX][N_MAX];

int main() {
    fin >> m >> n;
    for(int i = 1; i <= m; ++i)
        fin >> a[i];
    for(int i = 1; i <= n; ++i)
        fin >> b[i];

    for(int i = 1; i <= m; ++i) {
        for(int j = 1; j <= n; ++j) {
            if(a[i] == b[j])
                cmlsc[i][j] = cmlsc[i-1][j-1] + 1;
            else
                cmlsc[i][j] = max(cmlsc[i-1][j], cmlsc[i][j-1]);
        }
    }

    fout << cmlsc[m][n] << "\n";
    stack<int> res;

    while(m > 0 && n > 0) {
        if(a[m] == b[n]) {
            res.push(a[m]);
            m--, n--;
        }
        else
            if(cmlsc[m-1][n] > cmlsc[m][n-1])
                m--;
            else
                n--;
    }

    while(!res.empty()) {
        fout << res.top() << " ";
        res.pop();
    }
}
