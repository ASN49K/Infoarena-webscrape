#include <iostream>
#include <fstream>

using namespace std;

int m, n, mat[1025][1025], sir[1025], len;

int main() {
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    fin >> m >> n;
    int a[m+1], b[n+1];
    for(int i = 1; i <= m; i++)
        fin >> a[i];
    for(int i = 1; i <= n; i++)
        fin >> b[i];
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= n; j++) {
            if(a[i] == b[j])
                mat[i][j] = 1+mat[i-1][j-1];
            else
                mat[i][j] = max(mat[i-1][j], mat[i][j-1]);
        }

    for(int i = m, j = n; i; )
        if(a[i] == b[j]) {
            sir[++len] = a[i];
            --i;
            --j;
        } else if(mat[i-1][j] < mat[i][j-1]) {
            --j;
        } else --i;

    fout << len << endl;
    for(int i = len; i > 0; i--)
        fout << sir[i] << ' ';
    return 0;
}