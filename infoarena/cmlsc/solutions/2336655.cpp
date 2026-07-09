#include <fstream>
#define NM 1025
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,m,i,j;
int a[NM],b[NM],v[NM][NM],r[NM];
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++) f>>a[i];
    for(j=1;j<=m;j++) f>>b[j];
    for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
         if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
           else  v[i][j]=max(v[i][j-1],v[i-1][j]);
    i=n; j=m;
    while(i>0){
        if(a[i]==b[j]) { r[++r[0]]=a[i]; i--; j--; }
          else
        if(v[i-1][j]>v[i][j-1]) i--;
          else j--;
    }
    g<<r[0]<<'\n';
    for(i=r[0];i>=1;i--) g<<r[i]<<' ';
    return 0;
}
