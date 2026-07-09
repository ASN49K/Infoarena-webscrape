#include <bits/stdc++.h>

using namespace std;

int c[1050][1050];
vector<short> v;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    int n, m;
    short a[1050], b[1050];
    f >> n >> m;
    for(int i = 1; i <= n; i ++) f >> a[i];
    for(int i = 1; i <= m; i ++) f >> b[i];

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j])
                c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i][j - 1], c[i - 1][j]);
        }
    }

    g << c[n][m] << "\n";
    int wi = n, wj = m, maxx;

    while(c[wi][wj] != 0) {
        maxx = max(c[wi - 1][wj], c[wi][wj - 1]);
        if(c[wi][wj] == maxx) {
            if(c[wi][wj - 1] == maxx)
                wj --;
            else if(c[wi - 1][wj] == maxx)
                wi --;
        }
        else v.push_back(a[wi]), wi --, wj --;
    }

    reverse(v.begin(), v.end());
    for(auto i: v)
        g << i << " ";
    g << "\n";
    return 0;
}
