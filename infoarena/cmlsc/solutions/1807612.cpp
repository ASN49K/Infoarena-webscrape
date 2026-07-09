#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int i,j,n,m,mx,p,a[1025],b[1025],g[1025][1025],x[1025];

int main()
{
    fin>>n>>m;
    for(i=1;i<=n;i++)
    {
        fin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        fin>>b[i];
    }

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(a[i]==b[j]) g[i][j]=1+g[i-1][j-1];
            else
            {
                if(g[i-1][j]>g[i][j-1]) g[i][j]=g[i-1][j];
                else g[i][j]=g[i][j-1];
            }
        }
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(g[i][j]>mx)
            {
                mx=g[i][j];
                p++;
                x[p]=a[i];
            }
        }
    fout<<mx<<"\n";
    for(i=1;i<=p;i++)
        fout<<x[i]<<" ";

}
