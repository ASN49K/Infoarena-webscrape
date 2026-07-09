#include <bits/stdc++.h>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025], b[1025], d[1025][1025];
int ans[1025];
int bst;
int main(){
    int n, m;
    f >> m >> n;
    for(int i = 1; i <= m; ++i) f >> a[i];
    for(int i = 1; i <= n; ++i) f >> b[i];
    for(int i = 1; i <= m; ++i){
        for(int j = 1; j <= n; ++j){
            if(a[i] == b[j]) d[i][j] = 1 + d[i - 1][j - 1];
            else d[i][j] = max(d[i - 1][j], d[i][j - 1]);
        }
    }
    for(int i = m, j = n; i; ){
        if(a[i] == b[j]) ans[++bst] = a[i], --i, --j;
        else if(d[i - 1][j] < d[i][j - 1]) --j;
        else --i;
    }
    g << bst << endl;
    for(int i = bst; i; --i) g << ans[bst] << ' ';
    f.close();
    g.close();
    return 0;


}
