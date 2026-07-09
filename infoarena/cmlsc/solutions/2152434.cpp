#include <iostream>
#include <fstream>

using namespace std;

int a[1250], b[1250], c[1250][1250], n, m, d[1250], x=0;

void completare()
{
    for (int i=1; i<=n; i++)
        if (a[i]==b[1])
            c[1][i]=1+c[1][i-1];
        else
            c[1][i]=c[1][i-1];
    for (int i=1; i<=m; i++)
        if (a[1]==b[i])
            c[i][1]=1+c[i-1][1];
        else
            c[i][1]=c[i-1][1];
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
            if (a[i]==b[j])
            {
                c[i][j]=c[i-1][j-1]+1;
                if (c[i][j]>x)
                    d[x++]=a[i];
            }
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
    fin >> n >> m;
    for (int i=1; i<=n; i++)
        fin >> a[i];
    for (int j=1; j<=m; j++)
        fin >> b[j];
    completare();
    fout << x << "\n";
    for (int i=0; i<x; i++)
        fout << d[i] << " ";
    return 0;
}
