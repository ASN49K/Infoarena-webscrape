#include <iostream>
#include <fstream>
#define NMax 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int x[NMax],y[NMax],a[NMax][NMax];
int n,m;
int maxim (int x,int y,int z)
{
    if (x>=y && x>=z) return x;
    if (y>=x && y>=z) return y;
    return z;
}
void afiseaza (int i,int j)
{
    if (i>=1 && j>=1)
    {
        if (x[i]==y[j])
        {
            afiseaza(i-1,j-1);
            g<<x[i]<<" ";
        }
        else
        {
            if (a[i-1][j]>a[i][j-1]) afiseaza(i-1,j);
            else afiseaza(i,j-1);
        }
    }
}
int main ()
{
    int i,j;
    f>>n>>m;
    for (i=1;i<=n;i++) f>>x[i];
    for (j=1;j<=m;j++) f>>y[j];
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (x[i]==y[j]) a[i][j]=a[i-1][j-1]+1;
            else a[i][j]=maxim(a[i-1][j],a[i-1][j-1],a[i][j-1]);
        }
    }
    g<<a[n][m]<<'\n';
    afiseaza(n,m);
    g<<'\n';
}
