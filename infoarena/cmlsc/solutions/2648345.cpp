#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int d[1028][1028], n, m, a[1028], b[1028];

void citire()
{
    f>>m>>n;
    for(int i=1; i<=m; i++)
        f>>a[i];
    for(int j=1; j<=n; j++)
        f>>b[j];
}

void parcurgere()
{
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i][j-1], d[i-1][j]);
        }
}

void afisare(int lin, int col)
{
    if(!d[lin][col])
        return;
    if(a[lin]==b[col])
    {
        afisare(lin-1, col-1);
        g<<a[lin]<< ' ';
        return;
    }
    if(d[lin-1][col]>d[lin][col-1])
        afisare(lin-1, col);
    else
        afisare(lin, col-1);

}

void afisareelem()
{
    g<<d[m][n]<<'\n';
    afisare(m, n);
}
int main()
{
    citire();
    parcurgere();
    afisareelem();
    return 0;
}
