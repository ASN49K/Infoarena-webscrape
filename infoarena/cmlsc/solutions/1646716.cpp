#include<fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1025][1025],b[1025],c[1025],fin[1025],k,n,m,i,j;
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
      f>>b[i];
    for(j=1;j<=m;j++)
      f>>c[j];
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(b[i]==c[j])
          a[i][j]=a[i-1][j-1]+1;
        else
          a[i][j]=max(a[i-1][j],a[i][j-1]);
    i=n;
    j=m;
    while(a[i][j]!=0)
    {
        while(a[i-1][j]==a[i][j])
          i--;
        while(a[i][j-1]==a[i][j])
          j--;
        k++;
        fin[k]=b[i];
        i--;
        j--;
    }
    g<<a[n][m]<<"\n";
    for(i=k;i>=1;i--)
      g<<fin[i]<<" ";
    return 0;
}
