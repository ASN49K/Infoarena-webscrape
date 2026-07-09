#include<fstream.h>
long m,n,a[100],b[100],v[100],max,i,j; 
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int main()
{f>>m>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(j=1;j<=n;j++)
f>>b[j];
max=0;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
{max++;
v[max]=a[i];}
g<<max<<"\n";
for(i=1;i<=max;i++)
g<<v[i]<<" ";g.close();return 0;}
