#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
short v[1024][1025],a[1025],b[1025],sol[1025];
int i,j,MAX,n,m,k=0;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;++i) f>>a[i];
    for(i=1;i<=m;++i) f>>b[i];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
    {
        if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
        else v[i][j]=max(v[i-1][j],v[i][j-1]);
    }
    g<<v[n][m]<<'\n';
  /*  for(i=1;i<=n;++i)
    {
        for(j=1;j<=m;++j) g<<v[i][j]<<" ";
        g<<'\n';
    }*/
    i=n; j=m;
    while(i>0&&j>0)
    {
        if(v[i][j]!=v[i-1][j-1])
        { sol[++k]=a[i];
        //  g<<i<<"* "<<j<<'\n';
          i--;
          j--;
        }
        else
        {
            if(v[i][j]==v[i-1][j]&&i>=1) i--;
            else j--;
        }
    }
    for(i=k;i>=1;i--) g<<sol[i]<<" ";
    g<<'\n';
    f.close();
    g.close();
    return 0;
}
