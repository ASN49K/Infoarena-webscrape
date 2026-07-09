#include <bits/stdc++.h>
#define nmax 1024
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

unsigned short a[nmax], b[nmax], m[nmax][nmax], best[nmax], kbest;

int main(){
    unsigned short n, m, i, j;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (j = 1; j <= m; j++)
        fin >> b[j];
    for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
        if (a[i] == b[j])
            m[i][j] = m[i - 1][j - 1] + 1;
        else
            m[i][j] = max(m[i - 1][j], m[i][j - 1]);
    for (i = n, j = m; i; )
        if (a[i] == b[j]){
            best[++kbest] = a[i];
            i--;
            j--;
        }
        else if (m[i - 1][j] < m[i][j - 1])
            j--;
        else
            i--;
    fout << kbest << '\n';
    for (i = kbest; i; i--)
        fout << best[i] << ' ';
    fout << '\n';
    fin.close();
    fout.close();
    return 0;
}
