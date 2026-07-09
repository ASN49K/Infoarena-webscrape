#include <iostream>
#include <fstream>
using namespace std;
int main()


{int n,m,v[1024][1024],a[1024],b[1024],i,j,x,y,max,max1;
fstream f("cmlsc.in",ios::in);
fstream g("cmlsc.out",ios::out);
f>>m>>n;max1=0;
for(i=1;i<=m;i++)
    f>>a[i];
for(j=1;j<=n;j++)
    f>>b[j];
f.close();

for(i=1;i<=m;i++)
    {for(j=1;j<=n;j++)
    if(a[i]!=b[j])
    v[i][j]=0;
else
{max=0;
for(x=1;x<i;x++)
    for(y=1;y<j;y++)
    if(v[x][y]>max) max=v[x][y];
v[i][j]=1+max;
if(v[i][j]>max1) max1=v[i][j];

}
}
g<<max1;
g.close();
}
