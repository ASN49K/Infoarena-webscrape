#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1024 + 10;

int main(){
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");
    int n, m, a[maxn], b[maxn], d[maxn][maxn] = {}, rez[maxn] = {};
    f >> n >> m;
    for(int i = 1; i <= n; ++i) f >> a[i];
    for(int i = 1; i <= m; ++i) f >> b[i];

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]) d[i][j] = 1 + d[i-1][j-1];
            else d[i][j] = max(d[i-1][j], d[i][j-1]); } }

    int len = d[n][m];
    for(int i = n, j = m; len > 0; ){
        if(a[i] == b[j]) rez[len--] = a[i], --i, --j;
        else if(d[i-1][j] > d[i][j-1]) --i;
        else --j; }
    g << d[n][m] << '\n';
    for(int i = 1; i <= d[n][m]; ++i) g << rez[i] << ' ';
    return 0; }
