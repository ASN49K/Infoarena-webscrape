#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int n,i,j,m,a[1035][1035],b[1035],c[1035],sub[1035],x=0;
int main()
{ f>>n>>m;
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
        a[i][j]=max(a[i-1][j],a[i][j-1]);

}
 i=n;
 j=m;
 while(a[i][j])
 {
     while(a[i][j]==a[i-1][j])
        i--;
     while(a[i][j]==a[i][j-1])
        j--;


         x++;
     sub[x]=b[i];
     i--;
     j--;
 }
    g<<a[n][m]<<"\n";
    for(i=x;i>=1;i--)
        g<<sub[i]<<" ";
    return 0;
}
