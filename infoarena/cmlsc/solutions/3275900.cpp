#include <bits/stdc++.h>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int a[1025], b[1025], D[1025][1025];

void drum(int i, int j, int k) {
    if (k) {
        if (a[i] == b[j]) {
            drum(i - 1, j - 1, k - 1);
            fout << a[i] << ' ';
        } else {
            D[i - 1][j] > D[i][j - 1] ? drum(i - 1, j, k) : drum(i, j - 1, k);
        }
    }
    
    return;
}

int main(void) {
    int n, m;
    fin >> n >> m;
    
    for (int i = 1; i <= n; i++)
        fin >> a[i];
        
    for (int i = 1; i <= m; i++)
        fin >> b[i];
    
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j])
                D[i][j] = D[i - 1][j - 1] + 1;
            else
                D[i][j] = max(D[i - 1][j], D[i][j - 1]);
                
    fout << D[n][m] << '\n';
    drum(n, m, D[n][m]);
    
    return 0;
}