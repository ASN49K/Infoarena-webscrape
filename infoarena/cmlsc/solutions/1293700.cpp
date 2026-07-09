#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");
int a[1025][1025],x[1025],y[1025],i,j,m,n,c[1025],nr;
int main()
{
    fin>>m>>n;
    for(i=1;i<=m;i++)
        fin>>x[i];
    for(i=1;i<=n;i++)
        fin>>y[i];
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            if(x[i]==y[j])
                a[i][j]=a[i-1][j-1]+1;
            else
                a[i][j]=max(a[i-1][j],a[i][j-1]);
    i=m;
    j=n;
    nr=0;
    while(i>0&&j>0)
    {
        if(x[i]==y[j])
        {
            nr++;
            c[nr]=x[i];
            i--;
            j--;

        }
        else
            if(a[i][j]==a[i-1][j])
                i--;
            else
                j--;
    }
    fout<<a[m][n]<<'\n';
    for(i=nr;i>=1;i--)
        fout<<c[i]<<" ";
            return 0;
}
