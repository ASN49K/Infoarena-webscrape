#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int d[1028][1028], n, m, a[1028], b[1028], sir[1028], ct;

void citire()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>a[i];
    for(int j=1; j<=m; j++)
        f>>b[j];
}

void parcurgere()
{
    //d[i][j]=cel mai lung subsir comun din vec a pana la pozitia i si vec b pana la poz j
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
}

void afisareelem()
{
    g<<d[n][m]<<'\n';
    int i=n,j=m;
    while(i&&j)
    {
        if(a[i]==b[j])
        {
            sir[ct++]=a[i];
            i--;
            j--;
        }
        else if(d[i-1][j]>d[i][j-1])
            i--;
        else
            j--;
    }
    for(int i=ct-1; i>=0; i--)
        g<<sir[i]<<' ';
}

int main()
{
    citire();
    parcurgere();
    afisareelem();
    return 0;
}
