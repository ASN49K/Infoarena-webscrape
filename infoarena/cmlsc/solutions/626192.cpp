#include <fstream>
using namespace std;
#define maxim(a, b) (a > b ? a : b)
#define maxN 1025
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m, a[maxN], b[maxN], c[maxN][maxN];

int main()
{
    fin >> n >> m;
    for(int i = 1; i <= n; i++) fin >> a[i];
    for(int i = 1; i <= m; i++) fin >> b[i];

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            if(a[i] == b[j])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = maxim(c[i-1][j], c[i][j-1]);

    int i = n, j = m, comun[maxN], k = c[n][m];
    while(k)
        if(a[i] == b[j])
            comun[k--] = a[i], i--, j--;
        else if(c[i-1][j] < c[i][j-1])
            j--;
        else
            i--;

    fout << c[n][m] << '\n';
    for(i = 1; i <= c[n][m]; i++)
        fout << comun[i] << ' ';
    fout << '\n';

    return 0;
}
