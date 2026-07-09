#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n, m;
int a[1048], b[1048], d[1055][1055], s[1048];

int main()
{
    int i, j, k;
    fin >> n >> m;
    for (i = 1; i <= n; i++)
        fin >> a[i];
    for (i = 1; i <= m; i++)
        fin >> b[i];
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (a[i] == b[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j] = max(d[i-1][j], d[i][j-1]);
    fout << d[n][m] << "\n";
    k = 0;
    for (i = n, j = m; i > 0;)
        if (a[i] == b[j])
        {
            s[k++] = a[i];
            j--;
            i--;
        }
        else if (d[i-1][j] > d[i][j-1]) i--;
        else j--;
    for (i = k - 1; i >= 0; i--)
        fout << s[i] << " ";
    fout << "\n";
    return 0;
}
