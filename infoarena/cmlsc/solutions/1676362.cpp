#include <fstream>
#define NMax 1030
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[NMax], b[NMax], d[NMax][NMax],n,m,best,sir[NMax],i,j;
int main()
{    f>>m>>n;
      for(i=1;i<=m;i++)
        f>>a[i];
        for(j=1;j<=n;j++)
            f>>b[j];
        for(i=1;i<=m;i++)
            for(j=1;j<=n;j++)
               if(a[i]==b[j])
                  d[i][j]=1+d[i-1][j-1];
                else d[i][j]=max(d[i-1][j],d[i][j-1]);
        for(i=m,j=n;i;)
            if(a[i]==b[j])
               sir[++best]=a[i],--i,--j;
            else if(d[i-1][j]<d[i][j-1])
                   --j;
                 else --i;
      g<<best<<'\n';
      for(i=best;i;--i)
           g<<sir[i]<<' ';

    return 0;
}
