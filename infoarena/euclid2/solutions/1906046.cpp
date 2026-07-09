#include <bits/stdc++.h>
using namespace std;
void citire(int a[100][100],int &n,int &m)
{
ifstream f("flip.in");
f>>n>>m;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
f>>a[i][j];
}
int rezolva(int a[100][100],int n,int m,int x)
{
int s,rez=0;
for(int i=1;i<=n;i++)
{
s=0;
for(int j=1;j<=m;j++)
{
s+=(x & (1<<(j-1)))?a[i][j]:-a[i][j];
/** if(x & (1<<(j-1)))
cout<<"-";
else
cout<<"+"; **/
}
rez+=abs(s);
/// cout<<endl;
}
/// cout<<endl;
return rez;
}
int main()
{
int a[100][100],n,m,rez=0;
ofstream g("flip.out");
citire(a,n,m);
for(int ocupat=0;ocupat<(1<<m);ocupat++)
rez=max(rez,rezolva(a,n,m,ocupat));
g<<rez;
return 0;
}
