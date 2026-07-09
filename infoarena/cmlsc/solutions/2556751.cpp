#include <bits/stdc++.h>

using namespace std;

ifstream fin  ("cmlsc.in");
ofstream fout ("cmlsc.out");

int n, m, i, j, k;
int a[1050], b[1050], sol[1050], d[1050][1050];

int main(){
    fin >> n >> m;
    for (i=1; i<=n; i++){
        fin >> a[i];
    }
    for (i=1; i<=m; i++){
        fin >> b[i];
    }
    for (i=1; i<=n; i++){
        for (j=1; j<=m; j++){
            if (a[i] == b[j]){
                d[i][j] = d[i-1][j-1] + 1;
            }
            else {
                d[i][j] = max (d[i-1][j], d[i][j-1]);
            }
        }
    }
    i = n, j = m;
    while (i && j){
        if (a[i] == b[j]){
            sol[++k] = a[i];
            i--, j--;
        }
        else{
            if (d[i-1][j] > d[i][j-1]){
                i--;
            }
            else {
                j--;
            }
        }
    }
    fout << d[n][m] << "\n";
    for (i=k; i>=1; i--){
        fout << sol[i] << " ";
    }
    return 0;
}
//recapitulare
