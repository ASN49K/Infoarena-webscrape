#include <fstream>

using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int a[1026],b[1026],c[1026][1026],i,j,n,m,x,v[1026],p,q,nr;
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
}
int main()
{
   f>>n>>m;
   for(i=1;i<=n;i++)
    f>>a[i];
    for(i=1;i<=m;i++)
        f>>b[i];
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
            if(a[i]==b[j])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i-1][j],c[i][j-1]);
g<<c[n][m]<<'\n';
    x=c[n][m];
    p=n;q=m;
  while(p>0&&q>0)
            if(c[p][q]==c[p-1][q-1]+1){
                nr++;
                v[nr]=a[p];
                p--;q--;}
             else
               if(c[p][q]==c[p-1][q])
                  p--;
                  else
                    q--;
        for(i=nr;i>=1;i--)
            g<<v[i]<<" ";
    return 0;
}
