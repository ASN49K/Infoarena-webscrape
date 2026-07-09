#include <bits/stdc++.h>

using namespace std;

int c[1050][1050];
vector<int> v;

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    int n, m;
    int a[1050], b[1050];
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
    int wi = n, wj = m;

    while(c[wi][wj] != 0) {
        if(c[wi][wj] == c[wi - 1][wj - 1] + 1)
            v.push_back(a[wi]), wi --, wj --;
        else if(c[wi][wj - 1] > c[wi - 1][wj]) wj --;
        else wi --;
    }

    reverse(v.begin(), v.end());
    for(auto i: v)
        g << i << " ";
    g << "\n";
    return 0;
}
