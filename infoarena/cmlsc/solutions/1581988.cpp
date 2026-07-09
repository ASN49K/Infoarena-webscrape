#include <iostream>
#include <fstream>
using namespace std;
int main()


{int n,m,v[1024][1024],a[1024],b[1024],i,j,x,y,max,maxl,maxg;
fstream f("cmlsc.in",ios::in);
fstream g("cmlsc.out",ios::out);
f>>m>>n;
for(i=1;i<=m;i++)
    f>>a[i];
for(j=1;j<=n;j++)
    f>>b[j];
f.close();
max=0;maxl=0;
for(i=1;i<=m;i++)
    {for(j=1;j<=n;j++)
    {if(a[i]!=b[j])
    v[i][j]=0;
else
{v[i][j]=1+max;
if(max+1>maxl) maxl=max+1;
if(v[i][j]>maxg) maxg=v[i][j];

}
}
   max=maxl; }
g<<maxg;
g.close();
}
