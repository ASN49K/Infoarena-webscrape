#include <fstream>
using namespace std;
ifstream f ("cmlsc.in");
ofstream g ("cmlsc.out");
const int nmax=1e3+53;
int n,m,d[nmax][nmax],v1[nmax],v2[nmax],sol[nmax],k;
int main()
{
      f>>n>>m;
      for(int i=1;i<=n;++i) f>>v1[i];
      for(int j=1;j<=m;++j) f>>v2[j];
      for(int i=1;i<=n;++i)
      {
            for(int j=1;j<=m;++j)
            {
                  d[i][j]=max(d[i][j],max(d[i-1][j],d[i][j-1]));
                  if(v1[i]==v2[j]) d[i][j]=max(d[i][j],d[i-1][j-1]+1);
            }
      }
      int a=n,b=m;
      while(a&&b)
      {
            if(v1[a]==v2[b])
            {
                  sol[++k]=v1[a];
                  --a;
                  --b;
                  continue;
            }
            if(d[a-1][b]>d[a][b-1]) --a;
            else --b;
      }
      g<<d[n][m]<<'\n';
      for(int i=k;i>=1;--i) g<<sol[i]<<' ';
      return 0;
}
