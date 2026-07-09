#include <iostream>
#include <fstream>
using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
const int LIM = 1025;
int n, m, v[LIM], u[LIM], d[LIM][LIM], ct = 0;

int maxi(int n, int m)
{
    if(n < m)
        return m;
    else
        return n;
}

void subsir(int i, int j)
{
    if(i==0 || j==0) return;

    if(v[i] == u[j])
    {
        subsir(i-1, j-1);
        out<<v[i]<<" ";
        return;
    }

    if(d[i-1][j] > d[i][j-1])
        subsir(i-1, j);
    else
        subsir(i, j-1);
}

int main()
{
    in>>n>>m;
    for(int i=1; i<=n; i++)
    {
        in>>v[i];
    }
    for(int i=1; i<=m; i++)
    {
        in>>u[i];
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(v[i] == u[j])
                d[i][j] = 1 + d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j], d[i][j-1]);
        }
    }

    out<<d[n][m]<<"\n";
    subsir(n, m);
    return 0;
}
