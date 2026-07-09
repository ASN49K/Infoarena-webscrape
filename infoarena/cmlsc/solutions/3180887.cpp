#include <fstream>

using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int n,m,v[1025],q[1025],a[1025][1025],st[1025],i,j,x,k;
int main()
{
    fin >>n>>m;
    for (i=1;i<=n;i++)
    {
        fin >>v[i];
    }
    for (i=1;i<=m;i++)
    {
        fin >>q[i];
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=m;j++)
        {
            if (v[i]==q[j]) a[i][j]=1+a[i-1][j-1];
            else a[i][j]=max(a[i-1][j],a[i][j-1]);
        }
    }
    fout <<a[n][m]<<'\n';
    i=n;j=m;
    x=a[n][m];
    while (x)
    {
        if (v[i]==q[j])
        {
            k++;
            st[k]=v[i];
            x--;i--;j--;
        }
        else
        {
            if (a[i-1][j]==x) i--;
            else j--;
        }
    }
    for (i=k;i>=1;i--)
    {
        fout <<st[i]<<" ";
    }
    return 0;
}
