#include<fstream.h>
char a[1026],b[1026],s[1026][1026],c[1026];
int n,m,i,j,max=0,x,y,aux;
int main()
{ifstream f("cmlsc.in");ofstream g("cmlsc.out");f>>m;f>>n;
for(i=1;i<=m;i++)
f>>a[i];
for(i=1;i<=n;i++)
f>>b[i];


for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
if(a[i]==b[j])
 {max++;s[i][j]=s[i-1][j-1]+1;x=i;y=j;}
else
  if(s[i-1][j]>s[i][j-1])  s[i][j]=s[i-1][j];
  else s[i][j]=s[i][j-1];
 aux=max;

while(0<max)

if(a[x]==b[y])
   {c[max]=a[x];max--;x--;y--;}
else
    if(s[x-1][y]>s[x][y-1]) x--;
     else y--;




  g<<aux<<"\n";
  for(i=1;i<=aux;i++)
  g<<c[i]<<" ";



return 0;}

