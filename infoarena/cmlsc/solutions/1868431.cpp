#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;
ifstream in("cmlsc.in");
ofstream out("cmlsc.out");
int n,m,c[1025][1025],f[1025],g[1025],sol[1025];
int main()
{
   in>>n>>m;
   for(int i=1;i<=n;i++)
       in>>f[i];
   for(int i=1;i<=m;i++)
      in>>g[i];
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=m;j++)
          if(f[i]==g[j])
             c[i][j]=c[i-1][j-1]+1;
          else
            c[i][j]=max(c[i][j-1],c[i-1][j]);
   }
   out<<c[n][m]<<'\n';
   int k=0;
   for(int i=n,j=m;i;)
   {
       if(f[i]==g[j])
       {
           k++;
           sol[k]=f[i];
           i--,j--;
       }
       else
       {
          if(c[i-1][j]<c[i][j-1])
              j--;
          else
            i--;
       }
   }
   for(int i=k;i>=1;i--)
    out<<sol[i]<<" ";
}

