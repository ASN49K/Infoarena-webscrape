#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m,n,a[1030],b[1030],lcs[1030][1030],d[1030],d2,i,j;
int main()
{
    f>>m>>n;
    for(i=1;i<=m;++i)
      f>>a[i];
    for(i=1;i<=n;++i)
      f>>b[i];
    for(j=1;j<=n;++j)
      lcs[0][j]=0;
    for(i=1;i<=m;++i)
      lcs[i][0]=0;
    for(i=1;i<=m;++i)
      for(j=1;j<=n;++j)
          {if(a[i]==b[j])
            lcs[i][j]=1+lcs[i-1][j-1];
          else lcs[i][j]= max(lcs[i-1][j],lcs[i][j-1]); }
    g<<lcs[m][n]<<'\n';
    i=m;
    j=n;
    d2=0;
    while(lcs[i][j]!=0)
    {
        if(a[i]==b[j])
          {d[++d2]=a[i];
          --i;--j;}
        else{if(lcs[i][j]==lcs[i-1][j])
               i--;
             else j--;  }
    }
    for(i=1;i<=d2;++i)
      g<<d[i]<<" ";
    g<<'\n';

    return 0;
}
