#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

const int nmax=1030;
int a[nmax],b[nmax],mat[nmax][nmax],n,m,i,j,rez[nmax],k;

int main()
{
    f>>n>>m;
    for (i=1;i<=n;i++)
     f>>a[i];
    for (i=1;i<=m;i++)
     f>>b[i];

    for (i=1;i<=n;i++)
     for (j=1;j<=m;j++)
      {
          if (a[i]==b[j])
          mat[i][j]=mat[i-1][j-1]+1;
          else if (mat[i-1][j]>mat[i][j-1])
          mat[i][j]=mat[i-1][j];
          else
          mat[i][j]=mat[i][j-1];
      }
    g<<mat[n][m]<<'\n';

    while (k<=mat[n][m])
    {
        if (a[i]==b[j])
        {rez[++k]=a[i];
         i--;
         j--;
        }
        else if (mat[i-1][j]>mat[i][j-1])
        i--;
        else
        j--;
    }
    for (i=k;i>1;i--)
    g<<rez[i]<<" ";

    f.close();
    g.close();
    return 0;
}
