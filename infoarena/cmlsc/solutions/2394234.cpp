//#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>

using namespace std;
ifstream cin ("cmlsc.in");
ofstream cout ("cmlsc.out");

vector <int> x,y,v;
long long n,i,m,j,a,p,z[1025][1025];
int main()
{
    cin>>n>>m;
    x.resize(n+1);
    y.resize(m+1);
    for (i=1;i<=n;++i) cin>>x[i];

    for (i=1;i<=m;++i) cin>>y[i];

    for (i=1;i<=n;++i)
    {
        for (j=1;j<=m;++j)
        {
            if (x[i]==y[j]) z[i][j]=z[i-1][j-1]+1;
            else z[i][j]=max(z[i-1][j],z[i][j-1]);
        }
    }

    cout<<z[n][m]<<"\n";

    int db;
    db=0;
    i=n;
    j=m;
    v.resize(z[n][m]+1);
    while (z[i][j]!=0)
    {
       if (z[i-1][j]==z[i][j]) i-=1;
      else if (z[i][j-1]==z[i][j]) j-=1;
       else if (z[i][j]-1==z[i-1][j-1])
        {
            db++;
            v[db]=x[i];
            i-=1;
            j-=1;
        }

    }

    for (i=db;i>=1;--i) cout<<v[i]<<" ";
    return 0;
}
