#include <fstream>

using namespace std;
int a[1025][1025];
int li[1025];
int ci[1025];
int subs[1025],kl,m,n;
int main()
{int i,j;
ifstream in("cmlsc.in");
ofstream o("cmlsc.out");
in>>n>>m;
for(i=1;i<=n;++i)
    in>>li[i];
for(i=1;i<=m;++i)
    in>>ci[i];
for(i=1;i<=n;++i)
for(j=1;j<=m;++j)
{if(li[i]==ci[j]) a[i][j]=a[i-1][j-1]+1;
else {if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
      if(a[i-1][j]<a[i][j-1]) a[i][j]=a[i][j-1];
     }}

for(i=n,j=m;i;)
{
    if(li[i]==ci[j]) {subs[++kl]=ci[j];
    --j;
    --i;}
   else if(a[i-1][j]<a[i][j-1]) --j;
        else --i;
}
o<<kl<<'\n';
for(i=kl;i;--i)
    o<<subs[i]<<" ";
    o.close();
    return 0;
}
