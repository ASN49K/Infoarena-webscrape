#include <fstream>
using namespace std;
int v[1024][1024],i,j,a[1024],b[1024],n,m;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int max (int a,int b)
{if(a>b) return a;
else return b;}
void atz()
{for(i=1;i<=n;i++)
for(j=1;j<=m;j++) if(a[i]==b[j]) v[i][j]=v[i-1][j-1]+1;
		  else v[i][j]=max(v[i-1][j],v[i][j-1]);
		  cout<<v[n][m]<<"\n";
i=n;j=m;       }
void afisare(int i,int j)
{if(v[i][j]);
if(a[i]==b[j])
{afisare (i-1,j-1);if(a[i]!=0)cout<<a[i]<<" ";
}
else
{if(v[i][j]==v[i-1][j]) afisare(i-1,j);
else if(v[i][j]==v[i][j-1]) afisare(i,j-1);
}}

int main()
{

cin>>n>>m;
for(i=1;i<=n;i++) cin>>a[i];
for(j=1;j<=m;j++) cin>>b[j];
atz();
afisare(i,j);
}
