#include <fstream>

using namespace std;

ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");

int bst, a[1030], b[1030], c[1025][1025], rsp[1025];

int main ()
{
    int i, j, n, m;
    fin >> n >> m;

    for (i = 1; i <= n; i++) fin >> a[i];
    for (i = 1; i <= m; i++) fin >> b[i];

    for (i=1; i <= n; i++)
        for (j=1; j <= m; j++)
            if (a[i] == b[j])
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = ((c[i-1][j] < c[i][j-1]) ? c[i][j-1] : c[i-1][j]);

    for (i = n, j = m; i; )
        if (a[i] == b[j])
            rsp[++bst] = a[i], i--, j--;
        else if (c[i-1][j] < c[i][j-1])
            j--;
        else
            i--;

    fout << bst << '\n';
    for (int i=bst; i != 0; i--) fout << rsp[i] << ' ';


    return 0;
}
