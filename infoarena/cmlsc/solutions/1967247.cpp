#include <fstream>
using namespace std;

ifstream in ("cmlsc.in");
ofstream out ("cmlsc.out");

int n,m,f[1030][1030],v[1030],b[1030],a[1030],k;

void Read()
{
in>>n>>m;
for(int i=1;i<=n;i++)
in>>a[i];
for(int i=1;i<=m;i++)
in>>b[i];
}
void Solve()
{
for(int i=1;i<=n;i++)
{
for (int j=1;j<=m;j++)
{
if(a[i]==b[j])
f[i][j]=1+f[i-1][j-1];
else 
f[i][j]=max(f[i-1][j],f[i][j-1]);

}
}
for(int i=n,j=m;i and j;)
{
if(a[i]==b[j])v[k++]=a[i],i--,j--;
else if (f[i-1][j]<f[i][j-1])j--;
else i--;
}
}
void Print()
{
out<<k<<'\n';
for(int i=k;i>=1;i--)
out<<v[i]<<' ';
}

int main()
{
Read();
Solve();
Print();
return 0;
}
