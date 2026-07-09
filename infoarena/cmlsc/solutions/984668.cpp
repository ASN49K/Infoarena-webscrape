#include <fstream>
#include <cmath>
#define ll long long int
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int i,j,p,e,n,q,k;
int a[2000];
int b[2000];
int m[1025][1025];
int main()
{
cin>>n>>p;
for(i=1;i<=n;++i)cin>>a[i];
for(j=1;j<=p;++j)cin>>b[j];

for(i=1;i<=n;++i)
for(j=1;j<=p;++j)
if (a[i]==b[j])
m[i][j]=1+m[i-1][j-1];
else m[i][j]=max(m[i-1][j],m[i][j-1]);

cout<<m[n][p]<<" ";
for(i=1;i<=n;++i)
if(m[i][i])
if(m[i][i]!=m[i+1][i+1])
cout<<b[i]<<" ";

return 0;
}
