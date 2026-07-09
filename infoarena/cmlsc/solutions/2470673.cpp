#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
struct {
    int par;
    int ven;
}f[1026][1026];
int v[1026],v1[1026],fina[1026];
int main()
{
    int i,j,n,m;
    fin>>n>>m;
    for (i=1;i<=n;i++)
    {
        fin>>v[i];
    }
    for (i=1;i<=m;i++)
    {
        fin>>v1[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (v[i]==v1[j])
            {
                f[i][j].par=f[i-1][j-1].par+1;
                f[i][j].ven=2;
            }
            else
            {
                f[i][j].par=max(f[i-1][j].par,f[i][j-1].par);
                f[i][j].ven=1;
            }
        }
    }
    i=n;
    j=m;
    int u=0;
    while (i>=1 && j>=1)
    {
        if (v[i]==v1[j])
        {
            u++;
            fina[u]=v[i];
        }
        if (f[i][j].ven==2)
            {
                i--;
                j--;
            }
            else
            {
                if (f[i-1][j].par>f[i][j-1].par)
                    i--;
                else
                    j--;
            }
    }
    fout<<u<<"\n";
    for (i=u;i>=1;i--)
    {
        fout<<fina[i]<<" ";
    }
    return 0;
}
