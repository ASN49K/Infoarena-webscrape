#include <fstream>
#define max(a,b) a<b?b:a
using namespace std;
int n,m[1027][1027],i,j,q,w,k,a[1027],b[1027],rez[1027];
int main ()
{ifstream f("cmlsc.in");
 ofstream g("cmlsc.out");
f>>n>>q;
for(i=1;i<=n;i++)
f>>a[i];
for(j=1;j<=q;j++)
f>>b[j];
for(i=1;i<=n;i++)
for(j=1;j<=q;j++)
if(a[i]==b[j])
m[i][j]=m[i-1][j-1]+1;
else
m[i][j]=max(m[i][j-1],m[i-1][j]);
g<<m[n][q]<<'\n';
k=m[n][q];
w=k;
for(i=n;i;i--)
for(j=q;j;j--)
if(m[i][j]==k&&a[i]==b[j])
{rez[k]=a[i]; k--; n=i-1; q=j-1;}
for(i=1;i<=w;i++)
g<<rez[i]<<" ";
 f.close(); g.close();
return 0;
}
