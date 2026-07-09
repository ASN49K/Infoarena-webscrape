#include <fstream>

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025],b[1025],n,m,q[1025][1025],i,j,v[1025],nr;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;i++)
        f>>a[i];
    for(j=1;j<=n;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
        {
            if(b[i]!=a[j])
                q[i][j]=max(q[i][j-1],q[i-1][j]);
            else
            {
                q[i][j]=1+q[i-1][j-1];
                nr++;
            }
        }
    i=n;j=m;
    g<<nr<<'\n';
    nr=0;
    while(q[i][j]!=0)
    {
        if(b[i]=a[j])
        {
            i--;j--;
            v[++nr]=b[i];
        }
        else
            if(q[i-1][j]<q[i][j-1])
                j--;
            else
                i--;
    }
    for(i=nr-1;i>=1;i--)
        g<<v[i]<<" ";
    return 0;
}
