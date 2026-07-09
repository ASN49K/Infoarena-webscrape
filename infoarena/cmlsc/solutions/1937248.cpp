#include<fstream>
using namespace std;
int m,n,v[1025],w[1025],t[1025][1025],u[1025],Max;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{f>>m>>n;
for(int i=1;i<=m;i++)
f>>v[i];
for(int i=1;i<=n;i++)
f>>w[i];
for(int i=1;i<=m;i++)
for(int j=1;j<=n;j++)
if(v[i]==w[j])
t[i][j]=t[i-1][j-1]+1;
else
t[i][j]=max(t[i-1][j],t[i][j-1]);
Max=t[m][n];
g<<Max<<'\n';
for(int i=Max;i>=1;i--)
{while(t[m-1][n]==i)
m--;
while(t[m][n-1]==i)
n--;
u[i]=v[m];
}
for(int i=1;i<=Max;i++)
g<<u[i]<<' ';
return 0;
}
