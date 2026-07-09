#include <iostream>
#include <fstream>
#define maxn 1025
using namespace std;
int v[maxn][maxn];


int main()

{int i,j,a[maxn],b[maxn],m,n,max,x,y,maxim;
fstream f("cmlsc.in",ios::in);
fstream g("cmlsc.out",ios::out);
f>>m>>n;
maxim=0;


for(i=1;i<=m;i++)
    f>>a[i];

for(i=1;i<=n;i++)
    f>>b[i];

    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        v[i][j]=0;


  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(a[i]==b[j])
  {max=0;
      for(x=1;x<i;x++)
  for(y=1;y<j;y++)
  if(v[x][y]>max)
  max=v[x][y];

  v[i][j]=1+max;
  if(v[i][j]>maxim)
    maxim=v[i][j];
  }

g<<maxim<<'\n';

  max=1;
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
    if(v[i][j]==max)
    {g<<a[i]<<" ";
    max++;}


}




