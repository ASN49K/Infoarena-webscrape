#include <fstream>
#include <iostream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n, m, i, j;
int a[1025], b[1025];
int din[1025][1025];
int vs[1025], ns;

int main() {
    f >> n >> m;
    for (i = 1; i <= n; i++)
        f >> a[i];
    for (i = 1; i <= m; i++)
        f >> b[i];

    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if(a[i]==b[j]) din[i][j] = din[i-1][j-1]+1;
            else din[i][j] = max(din[i-1][j],din[i][j-1]);
    g << din[n][m] << '\n';

    i = n, j = m;
    while (i>0 && j>0) {
        while (din[i][j]==din[i][j-1] && i && j)j--;
        while (din[i][j]==din[i-1][j] && i && j)i--;
        vs[++ns] = i;
        i--,j--;
    }
    for (i = ns; i >= 1; i--)
        g << a[vs[i]] << ' ';

    return 0;
}
