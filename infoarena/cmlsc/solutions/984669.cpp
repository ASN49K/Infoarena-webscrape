#include <fstream>
#include <cmath>
#define ll long long int
using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int i,j,p,e,n,q,k,Cmlsc[1025];
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
i=n;j=p;
while(i&&j)
{
    if(a[i]==b[j])
    {
        Cmlsc[++k]=a[i];
        i--;j--;
    }
    else
        if(m[i-1][j]<m[i][j-1])
            j--;
        else
            i--;
}
    cout<<k<<"\n";
    for(i=k;i>0;i--)
        cout<<Cmlsc[i]<<" ";

return 0;
}
