#include<fstream.h>
char a[1026],b[1026],s[1026][1026],c[1026];
int n,m,i,j,max=0,w;
int main()
{ifstream f("cmlsc.in");ofstream g("cmlsc.out");f>>m;f>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(i=1;i<=n;i++)
f>>b[i];
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
 {max++;s[i][j]=max;}
else
  if(s[i-1][j]>s[i][j-1])  s[i][j]=s[i-1][j];
  else s[i][j]=s[i][j-1];
  i=0;w=0;

while(w<=max)
{i++;
for(j=1;j<=n;j++)
if(w<s[i][j])
   {w=s[i][j];c[w]=a[i];}}


  g<<max<<"\n";
  for(i=1;i<=max;i++)
  g<<c[i]<<" ";


  
return 0;}

