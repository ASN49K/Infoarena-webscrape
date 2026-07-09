#include <iostream>
#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int n,m,a[1025],b[1025],harta[1025][1025];

void citire()
{
    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>a[i];
    for(int i=1;i<=m;i++)
        f>>b[i];
}

void afisare()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            g<<harta[i][j]<<" ";
        g<<'\n';
    }
    g<<'\n';
}

void cmlsc()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j])
                harta[i][j]=harta[i-1][j-1]+1;
            else
                harta[i][j]=max(harta[i-1][j],harta[i][j-1]);
        }
        //afisare();
    }
}

void afisared(int i,int j)
{
    if(harta[i][j]==0)
        return;
    else
    {
        if(harta[i][j]>harta[i-1][j] && harta[i][j]>harta[i][j-1] && harta[i][j]==harta[i-1][j-1]+1)
        {
            afisared(i-1,j-1);
            g<<a[i]<<' ';
        }
        else
        {
        if(harta[i][j-1]>harta[i-1][j])
            afisared(i,j-1);
        else
            afisared(i-1,j);
        }
    }
}

int main()
{
    citire();
    cmlsc();
    g<<harta[n][m]<<'\n';
    afisared(n,m);
    return 0;
}
