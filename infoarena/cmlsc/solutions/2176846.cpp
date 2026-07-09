#include <fstream>
#define NM 1026
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j,k;
int a[NM],b[NM],v[NM][NM],r[NM];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(i=1;i<=m;i++) f>>b[i];
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
        if(a[i]!=b[j]) v[i][j]=max(v[i-1][j],v[i][j-1]);
         else          v[i][j]=v[i-1][j-1]+1;
    i=n; j=m;
    k=0;
    while(i>0){
        if(a[i]==b[j]){
          r[++k]=a[i];
          i--; j--;
        } else
        if(v[i-1][j]>v[i][j-1]) i--;
          else                  j--;
    }
    g<<v[n][m]<<'\n';
    for(i=k;i>=1;i--) g<<r[i]<<' ';
    return 0;
}
