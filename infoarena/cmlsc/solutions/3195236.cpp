#include <bits/stdc++.h>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n, m, i, a[1200], b[1200], sol[1200][1200], j;
int main()
{
    fin>>n>>m;
    for (i=1; i<=n;i ++) {
        fin>>a[i];
    }
    for (j=1; j<=m; j++) {
        fin>>b[i];
    }
    /// caz de baza cu prima linie si prima coloana
    for (i=2; i<=n; i++) {
        for (j=2; j<=m; j++) {
            sol[i][j]=max(sol[i-1][j], sol[i][j-1]);
            if (a[i]==b[j]) sol[i][j]=max(sol[i][j], sol[i-1][j-1]+1);
        }
    }
    fout<<sol[n][m];
    return 0;
}
