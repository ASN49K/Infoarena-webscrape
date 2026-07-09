#include <iostream>
#include <fstream>
using namespace std;
int main()
{int a[1025],b[1025],n,m,i,j,c[1025][1025],v1=1,v2=1,l=0;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
f>>n>>m;
for (i=1;i<=n;i++) f>>a[i];
for (i=1;i<=m;i++) f>>b[i];
for (i=1;i<=n;i++)
{
for (j=1;j<=m;j++)
{if (a[i]==b[j]) {c[i][j]=a[i];}
else c[i][j]=0;
}}
for (i=1;i<=n;i++)
{for (j=1;j<=m;j++)
{if ((c[i][j]!=0)&&(i>=v1)&&(j>=v2)) {v1=i;
                                   v2=j;
                                   l=l+1;}}}
v1=0;
v2=0;
g<<l<<endl;
for (i=1;i<=n;i++)
{for (j=1;j<=m;j++)
{if ((c[i][j]!=0)&&(i>=v1)&&(j>=v2)) {v1=i;
                                   v2=j;
                                   l=l+1;
                                   g<<c[i][j]<<" ";}}}
f.close();
g.close();
return 0;
}
