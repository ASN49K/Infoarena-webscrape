#include <fstream>
#include <cstring>
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int n,m,i,j,d[1025][1025],v[1025],a[1025],rez[1025],k;
int main()
{
    cin>>n>>m;
    for (i=1;i<=n;++i)
         cin>>v[i];
    for (i=1;i<=m;++i)
         cin>>a[i];
    for (i=1; i<=n; ++i)
    {
        for (j=1; j<=m; ++j)
        {
            if (v[i]==a[j])
                d[i][j]=1+d[i-1][j-1];
            else
                d[i][j]=max(d[i][j-1],d[i-1][j]);
        }
    }
    i=n;
    j=m;
    while (i && j)
    {
        if (v[i]==a[j])
        {
            rez[++k]=v[i];
            i--;
            j--;
        }
        else if (v[i]!=a[j])
        {
            if (d[i][j]==d[i][j-1] && d[i][j]!=d[i-1][j]) j--;
            else if (d[i][j]==d[i-1][j] && d[i][j]!=d[i][j-1]) i--;
            else
            {
                if (i>1) i--;
                else j--;
            }

        }
    }
    cout<<k<<"\n";
    for (i=k;i>=1;--i) cout<<rez[i]<<" ";
    cout<<"\n";

}
