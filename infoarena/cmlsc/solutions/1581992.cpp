#include <iostream>
#include <fstream>

using namespace std;
int main()


{int n,m,v[1024][1024],a[1024],b[1024],i,j,max,maxl,max2;
fstream f("cmlsc.in",ios::in);
fstream g("cmlsc.out",ios::out);
f>>m>>n;
for(i=1;i<=m;i++)
    f>>a[i];
for(j=1;j<=n;j++)
    f>>b[j];
f.close();
max=0;maxl=0;max2=0;
for(i=1;i<=m;i++)
    {for(j=1;j<=n;j++)
    {if(a[i]!=b[j])
    v[i][j]=0;
else
{v[i][j]=1+max;
if(max+1>maxl) maxl=max+1;
if(v[i][j]>max2) max2=v[i][j];

}
}
   max=maxl; }
g<<max2;
g.close();
}
