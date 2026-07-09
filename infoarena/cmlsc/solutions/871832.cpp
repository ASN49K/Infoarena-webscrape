#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1026][1026],b[1026],c[1026],n,m,i,j,k,x[1026];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
     f>>b[i];
    for(i=1;i<=m;i++)
     f>>c[i];
    for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {
         if(b[i]==c[j])
          a[i][j]=a[i-1][j-1]+1;
         else
          a[i][j]=max(a[i][j-1],a[i-1][j]);
     }
     g<<a[n][m]<<"\n";
     i=n;
     j=m;
     while(a[i][j])
     {
         while(a[i][j]==a[i-1][j])
          i--;
         while(a[i][j]==a[i][j-1])
          j--;
        k++;
        x[k]=b[i];
        i--;
        j--;
     }
     for(i=k;i>=1;i--)
      g<<x[i]<<" ";
}
