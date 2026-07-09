#include <fstream>

using namespace std;
int a[1025][1025];
int li[1025];
int ci[1025];
int subs[1025],k,m,n;
int main()
{int i,j;
ifstream in("cmlsc.in");
ofstream o("cmlsc.out");
in>>m>>n;
for(i=1;i<=m;++i)
    in>>li[i];
for(i=1;i<=n;++i)
    in>>ci[i];
for(i=1;i<=m;++i)
for(j=1;j<=n;++j)
{if(li[i]==ci[j]) a[i][j]=a[i-1][j-1]+1;
else {if(a[i-1][j]>a[i][j-1]) a[i][j]=a[i-1][j];
      if(a[i-1][j]<a[i][j-1]) a[i][j]=a[i][j-1];
     }}

for(i=m,j=n;i;)
{
    if(li[i]==ci[j]) {subs[++k]=ci[j];
    --j;
    --i;}
   else if(a[i-1][j]<a[i][j-1]) --j;
        else --i;
}
o<<k<<'\n';
for(i=k;i;--i)
    o<<subs[i]<<" ";
    o.close();
    return 0;
}
