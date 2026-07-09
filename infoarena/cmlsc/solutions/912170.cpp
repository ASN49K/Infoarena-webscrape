#include <iostream>
#include <fstream>
using namespace std;
int n,m,a[1025],b[1025],d[1025][1025];
ofstream g("cmlsc.out");

void citire()
{
    ifstream f("cmlsc.in");
    f >> n >> m;
    int i;
    for(i=1; i<=n; i++)
        f >> a[i];
    for(i=1; i<=m; i++)
        f >> b[i];
}

int max(int a, int b)
{
    if(a>b)
        return a;
    return b;
}

void afisare(int i, int j)
{
    if(i>0 && j >0)
    {
        if(a[i]==b[j])
        {
            afisare(i-1,j-1);
            g << a[i] << ' ';
        }
        else
        {
            int x=max(d[i-1][j],d[i][j-1]);
            if(x==d[i-1][j])
                afisare(i-1,j);
            else
                afisare(i,j-1);
        }
    }
}

void PD()
{
    int i,j;
    for(i=1; i<=n; i++)
        for(j=1; j<=m; j++)
        {
            if(a[i]==b[j])
                d[i][j]=d[i-1][j-1]+1;
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
        }
    g << d[n][m] << endl;
    afisare(n,m);
    g.close();
}

int main()
{
    citire();
    PD();
    return 0;
}
