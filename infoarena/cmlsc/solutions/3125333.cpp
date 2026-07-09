#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030][1030];
int v1[1030];
int v2[1030];
int sol[1030];
int main()
{
    int n,i,j,m,k = 0;
    fin >> n >> m;
    for(i = 1; i <= n; i++) fin >> v1[i];
    for(i = 1; i <= m; i++) fin >> v2[i];
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(v1[i] == v2[j]) a[i][j] = a[i - 1][j - 1] + 1;
            else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    }
    /*for(i = 0; i <= n; i++){
        for(j = 0; j <= m; j++) fout << a[i][j] << " ";
        fout << "\n";
    }*/
    fout << a[n][m] << "\n";
    int x = n, y = m;
    while(k < a[n][m]){
        if(a[x][y] == a[x - 1][y - 1] + 1 && a[x][y] > a[x - 1][y] && a[x][y] > a[x][y - 1]){
            x--;
            y--;
            sol[++k] = v1[x + 1];
        }
        else if(a[x - 1][y] < a[x][y - 1]) y--;
        else x--;
    }
    for(i = k; i >= 1; i--){
        fout << sol[i] << " ";
    }
    return 0;
}
