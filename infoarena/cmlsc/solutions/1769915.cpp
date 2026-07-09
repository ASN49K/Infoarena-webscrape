#include <iostream>
#include <fstream>

using namespace std;

int n, m;
short a[1025], b[1025], c[1025][1025];

int main()
{
    ifstream f("cmlsc.in");
    ofstream g("cmlsc.out");

    f >> n >> m;
    for(int i = 1; i <= n; i ++) {
        f >> a[i];
    }

    for(int i = 1; i <= m; i ++) {
        f >> b[i];
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= m; j ++) {
            if(a[i] == b[j]) c[i][j] = c[i - 1][j - 1] + 1;
            else c[i][j] = max(c[i - 1][j], c[i][j - 1]);
        }
    }

    int v[1025];
    int r = c[n][m];

    g << c[n][m] << "\n";
    int i = n, j = m;

    for(; i > 0 && j > 0; ) {
        for(; j > 0; ) {
            if(a[i] == b[j])
                v[r] = a[i], i --, j --, r --;
            else {
                if(c[i][j - 1] > c[i - 1][j]) j --;
                else i --;
            }
        }
    }
    for(int i = 1; i <= c[n][m]; i ++) g << v[i] << " ";
    g << "\n";
    return 0;
}
