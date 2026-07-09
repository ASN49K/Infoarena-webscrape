#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,v[1025],w[1025],a[1025][1025],rez[1025],k;
int main()
{
    f>>n>>m;
    for(int i=1; i<=n; i++)
        f>>v[i];
    for(int j=1; j<=m; j++)
        f>>w[j];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(v[i]==w[j])
            {
                a[i][j]=1+a[i-1][j-1];
            }
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    int i,j;
    for (i=n, j=m; i; )
    {
        if(v[i]==w[j])
        {
            rez[++k]=v[i];
            i--;
            j--;
        }
        else
        {
            if(a[i-1][j]<a[i][j-1])
                j--;
            else
                i--;
        }
    }
    g<<k<<'\n';
    for(int i=k; i>=1; i--)
        g<<rez[i]<<" ";
}
