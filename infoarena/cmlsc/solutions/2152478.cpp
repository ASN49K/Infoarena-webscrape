#include <iostream>
#include <fstream>

using namespace std;

int a[1250], b[1250], c[1250][1250], n, m, d[1250], x=0;

void completare()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                if (c[i][j-1]>c[i-1][j])
                    c[i][j]=c[i][j-1];
                else
                    c[i][j]=c[i-1][j];
}

int main()
{
    ifstream fin("cmlsc.in");
    ofstream fout("cmlsc.out");
    int i, j;
    fin >> n >> m;
    for (i=1; i<=n; i++)
        fin >> a[i];
    for (j=1; j<=m; j++)
        fin >> b[j];
    completare();
    i=n;
    j=m;
    while (c[i][j])
    {
        if (a[i]==b[j])
        {
            d[x++]=a[i];
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
    fout << x << "\n";
    for (i=x-1; i>=0; i--)
        fout << d[i] << " ";
    return 0;
}
