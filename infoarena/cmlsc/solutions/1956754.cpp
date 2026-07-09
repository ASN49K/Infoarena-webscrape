#include <fstream>
#define nmax 1030
using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

unsigned short a[nmax], b[nmax], c[nmax][nmax], best[nmax], kbest;

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
            c[i][j] = 1 + c[i - 1][j - 1];
        else
            c[i][j] = max(c[i - 1][j], c[i][j - 1]);
    for (i = n, j = m; i; )
        if (a[i] == b[j]){
            best[++kbest] = a[i];
            i--;
            j--;
        }
        else if (c[i - 1][j] < c[i][j - 1])
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
