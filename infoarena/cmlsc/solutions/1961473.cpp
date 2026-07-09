#include <iostream>
#include <fstream>

using namespace std;

int c[1030][1030], a[1030], b[1030], d[1030];

int max(int a, int b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ifstream fin ("cmlsc.in");
    ofstream fout ("cmlsc.out");
    int n, m, i, j, x=0;
    fin >> m >> n;
    for (i=1; i<=m; i++)
        fin >> a[i];
    for (i=1; i<=n; i++)
        fin >> b[i];
    for (i=1; i<=n; i++)
        for (j=1; j<=m; j++)
            if (a[j]==b[i])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j], c[i][j-1]);
    fout << c[n][m] << "\n";
    i=n;
    j=m;
    while (c[i][j])
    {
        if (a[j]==b[i])
        {
            d[++x]=a[j];
            i--;
            j--;
        }
        else
        {
            if (c[i-1][j]==c[i][j])
                i--;
            else
                j--;
        }
    }
    for (i=x; i>=1; i--)
        fout << d[i] << " ";
    return 0;
}
