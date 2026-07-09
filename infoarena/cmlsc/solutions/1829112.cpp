#include <fstream>

using namespace std;
ifstream cin("cmlsc.in");
ofstream cout("cmlsc.out");
int a[1025],b[1025],c[1025][1025],n,m;
void citire()
{
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=m;++i) cin>>b[i];
}
int maxim(int g,int h)
{
    if(h>g) return h;
    return g;
}

void dinamica()
{  for (int i=0;i<=n;++i)
     c[0][i]=0;
   for (int i=0;i<=m;++i)
     c[i][0]=0;

    for(int i=1;i<=n;++i)
       for(int j=1;j<=m;++j)
       {
           if(a[i]!=b[j])
              c[i][j]=maxim(c[i-1][j],c[i][j-1]);
           else if(a[i]==b[j])
              c[i][j]=1+c[i-1][j-1];
       }
       cout<<c[n][m]<<endl;
int x=n,y=m;
int o[1025],po=0;
while(c[x][y]!=0)
{if(a[x]==b[y])
   { ++po;
     o[po]=a[x];
    --x;--y;
   }
else  if(maxim(c[x-1][y],c[x][y-1])==c[x-1][y])--x;

      else --y;
}
for(int i=po;i>=1;--i)
    cout<<o[i]<<" ";





}
int main()
{citire();
dinamica();
    return 0;
}
