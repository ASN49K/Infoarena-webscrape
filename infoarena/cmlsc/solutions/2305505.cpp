#include <iostream>
#include <fstream>

using namespace std;

short x[1025],y[1025],n,m;
short L[1025][1025];
ofstream g("cmlsc.out");
void afis(int i=n,int j=m)
{
    if(i>0 && j>0)
    {
        if(x[i]==y[j])
        {
            afis(i-1,j-1);
            g<<x[i]<<' ';
        }
        else
            L[i-1][j]>L[i][j-1]? afis(i-1,j) : afis(i,j-1);
    }
}

int main()
{
    ifstream f("cmlsc.in");

    f>>n>>m;
    for(int i=1;i<=n;i++)
        f>>x[i];
    for(int i=1;i<=m;i++)
        f>>y[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(x[i]==y[j])
                L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
    g<<L[n][m]<<'\n';
    afis();
    f.close();
    g.close();
    return 0;
}
