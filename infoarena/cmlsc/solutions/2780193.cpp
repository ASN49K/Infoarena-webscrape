#include <bits/stdc++.h>
using namespace std;
ifstream fin("subsir.in");
ofstream fout("subsir.out");
#define NMAX 1005
int n, m, bst, a[NMAX][NMAX];
int x[NMAX], y[NMAX], sir[NMAX];
int main()
{
    fin >> n >> m;
    for (int i=1;i<=n;i++)
        fin >> x[i];
    for (int i=1;i<=m;i++)
        fin >> y[i];
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (x[i] == y[j]){
                a[i][j] = 1 + a[i-1][j-1];
            }else{
                a[i-1][j-1] = max(a[i][j-1], a[i-1][j]);
            }
        }
    }
    bst = a[n][m];
    fout << bst << '\n';
    for (int i=1, j=1; i<=n && j<=m;)
        if (x[i] == y[j]){
            sir[++bst] = x[i];
            ++i;
            ++j;
        }else if (a[i][j-1] < a[i-1][j]){
            ++j;
        }else{
            ++i;
        }

    for (int i=1;i<=bst;++i){
        fout << sir[i];
    }
    fout << '\n';
    return 0;
}
