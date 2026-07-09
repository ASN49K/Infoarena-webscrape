#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int c[1025][1025],a[1025],b[1025],n,m;

void afla(int i,int j)
{
    if (i>=1&&j>=1)
        if (a[i]!=b[j])

            if (c[i][j-1]>c[i-1][j]) afla(i,j-1);
            else afla(i-1,j);

        else
        {
            afla(i-1,j-1);
            g<<a[i]<<' ';
        }
}

void rezolvare()
{
    int i,j;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if (a[i]==b[j]) c[i][j]=1+c[i-1][j-1];
            else c[i][j]=max(c[i-1][j],c[i][j-1]);
    g<<c[n][m]<<'\n';
    afla(n,m);
}

void citire()
{
    int i;
    f>>n>>m;
    for (i=1;i<=n;i++) f>>a[i];
    for (i=1;i<=m;i++) f>>b[i];
}

int main()
{
    citire();
    rezolvare();
    return 0;
}
