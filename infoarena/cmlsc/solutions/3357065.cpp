#include <bits/stdc++.h>
#define MAXN 1024

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[MAXN + 1], b[MAXN + 1], lung[MAXN + 1][MAXN + 1];

void refac(int i, int j){

    if(lung[i][j] > 0){
        if(a[i] == b[j]){
            refac(i - 1, j - 1);
            fout << a[i] << " ";
        }else{
            if(lung[i - 1][j] >= lung[i][j - 1]){
                refac(i - 1, j);
            }else{
                refac(i, j - 1);
            }
        }
    }
}

int main()
{
    int n, m, i, j;

    fin >> n >> m;
    for(i = 1; i <= n; i++){
        fin >> a[i];
    }
    for(i = 1; i <= m; i++){
        fin >> b[i];
    }


    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(a[i] == b[j]){
                lung[i][j] = lung[i - 1][j - 1] + 1;
            }else{
                lung[i][j] = max(lung[i - 1][j], lung[i][j - 1]);
            }
        }
    }
    fout << lung[n][m] << "\n";

    refac(n, m);
    return 0;
}
