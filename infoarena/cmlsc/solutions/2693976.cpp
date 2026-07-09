#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, bst, sir[1030], x[1050], y[1050], a[1030][1030];
int main() {
    fin >> n >> m;
    for (int i=1;i<=n;i++){
        fin >> x[i];
    }
    for (int i=1;i<=m;i++){
        fin >> y[i];
    }

    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (x[i] == y[j]){
                a[i][j] = 1 + a[i-1][j-1];
            }else{
                a[i][j] = max(a[i-1][j], a[i][j-1]);
            }
        }
    }

    fout << a[n][m] << '\n';

    for (int i=n, j=m; i;)
        if (x[i] == y[j]){
            sir[++bst] = x[i];
            --i;
            --j;
        }else if (a[i-1][j] < a[i][j-1]){
            --j;
        }else{
            --i;
        }

    for (int i=bst;i;--i){
        fout << sir[i] << " ";
    }
    fout << '\n';
    return 0;
}
