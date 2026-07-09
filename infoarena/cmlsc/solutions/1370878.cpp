#include <fstream>

using namespace std;
int n,m,a[1030],b[1030],d[1030][1030],sir[1030],k,i,j;
int main()
{ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
 f>>n>>m;
 for (i=1;i<=n;i++)
 f>>a[i];
 for (j=1;j<=m;j++)
 f>>b[j];
 for (i=1;i<=n;i++)
 for (j=1;j<=m;j++)
 if(a[i]==b[j])
 d[i][j]=1+d[i-1][j-1];
 else d[i][j]=max(d[i-1][j],d[i][j-1]);
 g<<d[n][m]<<'\n';
 while (d[n][m])
 { if(a[n]==b[m])
   { sir[++k]=a[n];
    n--;
    m--;
   }
   else if(d[n][m-1]>d[n-1][m])
      m--;
    else n--;
 }

 for (i=k;i>=1;i--)
 g<<sir[i]<<' ';

    return 0;
}
