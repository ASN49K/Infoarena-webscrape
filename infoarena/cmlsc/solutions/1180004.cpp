#include<iostream>
#include<fstream>
using namespace std;

int a[1025],b[1025],i,j,m,r,t,k,n,e[1025];
int c[1025][1025],d[1025][1025];
int main()
{
ifstream f("cmlsc.in");  ofstream g("cmlsc.out");
f>>n>>m;
for(i=1;i<=n;i++) f>>a[i];
for(i=1;i<=n;i++) f>>b[i];

for(i=1;i<=n;i++)
for(j=1;j<=m;j++)
  if(a[i]==b[j])
       c[i][j] = c[i-1][j-1] + 1, d[i][j]  = 1;
  else
     if(c[i-1][j] > c[i][j-1]) c[i][j] = c[i-1][j], d[i][j] = 2;
     else c[i][j] = c[i][j-1], d[i][j] = 3;
     

g<<c[n][m]<<"\n";
i = n; j = m;
while(i>0 && j>0)
{
   if(a[i] == b[j]) k++, e[k] = a[i];
   if(d[i][j] == 1) j--,i--;
   if(d[i][j] == 2) i--;
   if(d[i][j] == 3) j--;
}

for(i=k;i>=1;i--) g<<e[i]<<" ";


f.close(); g.close();
return 0;
}
