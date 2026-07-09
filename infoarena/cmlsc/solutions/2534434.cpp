#include <bits/stdc++.h>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, mat[1001][1001], a[1024], b[1024], v[1024], k = 1;

int main(){
    fin>>n;
    fin>>m;
    for(int i = 1; i <= n; ++i)
        fin>>a[i];
    for(int i = 1; i <= m; ++i)
        fin>>b[i];
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(a[i] == b[j]){
                mat[i][j] = mat[i-1][j] + 1;
                v[k] = a[i];
                ++k;
            }
            else
                mat[i][j] = max(mat[i][j-1], mat[i-1][j]);
        }
    }
    fout<<mat[n][m]<<'\n';
    for(int i = 1; i < k; ++i)
        fout<<v[i]<<' ';


}
