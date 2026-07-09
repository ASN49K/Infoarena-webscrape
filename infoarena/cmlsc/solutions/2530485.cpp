#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int main() {
    int n, m;
    fin >> n >> m;
    int v1[n], v2[m], M[n+1][m+1] {};

    for(int i = 0; i < n; ++i)
        fin >> v1[i];
    for(int i = 0; i < m; ++i)
        fin >> v2[i];

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            if(v1[i-1] == v2[j-1])
                M[i][j] = 1 + M[i-1][j-1];
            else
                M[i][j] = max(M[i-1][j], M[i][j-1]);

    int r[M[n][m]], c = 0;

    int i = n, j = m;

    while(i)
        if(v1[i-1] == v2[j-1]) {
            r[c] = v1[i-1];
            c++;
            i--;
            j--;
        }
        else if(M[i][j-1] < M[i-1][j])
            i--;
        else
            j--;

    fout << M[n][m] << '\n';
    for(int i = c-1; i >= 0; --i)
        fout << r[i] << ' ';
}
