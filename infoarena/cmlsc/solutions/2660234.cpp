#include <iostream>
#include <fstream>
using namespace std;
int x[1025],y[1025],d[1025][1025],i,j,n,m;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
void afisare(int m, int n)
{
    if (!m||!n) return;
    if (x[m]==y[n])
    {
        afisare(m-1,n-1);
        out<<x[m]<<" ";
    }
    else if (d[m-1][n]>d[m][n-1])
        afisare(m-1,n);
    else
        afisare(m,n-1);
}
int main()
{
    in>>m>>n;
    for (i=1; i<=m; i++)
        in>>x[i];
    for (i=1; i<=n; i++)
        in>>y[i];
    for (i=1; i<=m; i++)
        for (j=1; j<=n; j++)
            if (x[i]==y[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i-1][j],d[i][j-1]);
    out<<d[m][n]<<endl;
    afisare(m,n);
}
