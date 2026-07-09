#include <bits/stdc++.h>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1030][1030];
int v1[1030];
int v2[1030];
int main()
{
    int n,i,j,m;
    fin >> n >> m;
    for(i = 1; i <= n; i++) fin >> v1[i];
    for(i = 1; i <= m; i++) fin >> v2[i];
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(v1[i] == v2[j]) a[i][j] = a[i - 1][j - 1] + 1;
            else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
        }
    }
    fout << a[n][m] << "\n";
    for(i = 1; i <= n; i++){
        if(a[i][m] == a[i - 1][m] + 1)
            fout << v1[i] << " ";
    }
    return 0;
}
