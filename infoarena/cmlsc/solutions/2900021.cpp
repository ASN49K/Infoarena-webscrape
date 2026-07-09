#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[1025], b[1025], v[1025][1025], k, idk[1025];

int main(){
    fin >> n >> m;
    for(int i = 1; i <= n; i++)
        fin >> a[i];
    for(int j = 1; j <= m; j++)
        fin >> b[j];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i] == b[j])
                v[i][j] = v[i-1][j-1] + 1;
            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
        }
    }
    fout << v[n][m] << '\n';
    for(int i = n; i >= 1 && k < v[n][m]; i--)
        for(int j = m; j >= 1 && k < v[n][m]; j--)
            if(a[i] == b[j])
                idk[++k] = a[i];
    for(int i = k; i >= 1; i--)
        fout << idk[i] << ' ';
}