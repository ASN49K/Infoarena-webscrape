#include <iostream>
#include <fstream>

#define lmax 1025

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int m,n,best;
int a[lmax],b[lmax],d[lmax][lmax],sc[lmax];

void citire()
{
    fin>>m>>n;
    for (int i=1; i<=m; ++i) fin>>a[i];
    for (int i=1; i<=n; ++i) fin>>b[i];
}

void pd()
{
    for (int i=1; i<=m; ++i)
        for (int j=1; j<=n; ++j)
    {
        if (a[i]==b[j])
            d[i][j]=d[i-1][j-1]+1;
        else
            d[i][j]=max(d[i-1][j],d[i][j-1]);
    }

    for (int i=m, j=n; i; )
    {
        if (a[i]==b[j])
            sc[++best]=a[i], --i, --j;
        else if (d[i-1][j]>d[i][j-1])
            --i;
        else
            --j;
    }
    fout<<best<<'\n';
    while (best)
        fout<<sc[best--]<<' ';
}

int main()
{
    citire();
    pd();
    return 0;
}
