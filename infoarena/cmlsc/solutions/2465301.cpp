#include <fstream>

using namespace std;

int N[1025],M[1025],f[1025][1025],s[1025];

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int main()
{
    int n,m,i,j,best=0;
    in>>n>>m;
    for (i=1;i<=n;i++)
        in>>N[i];
    for (j=1;j<=m;j++)
        in>>M[j];
    for (i=1;i<=m;i++)
        for (j=1;j<=m;j++)
    {
      if (N[i]==M[j])
            f[i][j]=f[i-1][j-1]+1;
      else
        f[i][j]=max(f[i-1][j],f[i][j-1]);
    }
    for (i=n,j=m;i&&j;)
        {
          if (N[i]==M[j])
             s[++best]=N[i],i--,j--;
          else if (f[i-1][j]<f[i][j-1])
             j--;
          else
            i--;
        }
    out<<best<<'\n';
    for (i=best;i>0;i--)
        out<<s[i]<<" ";
    return 0;
}
