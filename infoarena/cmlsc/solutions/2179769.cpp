#include <iostream>
#include <fstream>
using namespace std;
ifstream fin ("cmlsc.in");
ofstream fout ("cmlsc.out");
int a[1026], i, n, d[1026][1026], b[1026], v[1026], m, j, k;
int main()
{
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (i=1; i<=m; i++)
        fin >> b[i];
    fin.close();
    for (i=n; i>=1; i--)
        for (j=m; j>=1; j--)
        if (a[i] == b[j])
        d[i][j] = d[i+1][j+1] + 1;
        else if (d[i+1][j] > d[i][j+1])
           d[i][j] = d[i+1][j];
        else d[i][j] = d[i][j+1];
    i = 1;
    j = 1;
    while (i <= n && j <= m)
        if (a[i] == b[j])
        {
            v[++k] = a[i];
            i++;
            j++;
        }
        else if (d[i+1][j] < d[i][j+1])
            j++;
        else i++;
     fout << k<< "\n";
     for (i=1; i<=k; i++)
            fout << v[i]<<" ";
     fout.close();
    return 0;
}
