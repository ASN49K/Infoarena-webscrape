#include <iostream>
#include <fstream>

#define max(a,b) ((a>b) ? a : b)

using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int main(){
      int n,m,i,j,a[1024],b[1024],c[1024][1024];
      f>>n>>m;
      
      for(i = 1; i <= n; i++)
            f>>a[i];
      for(i = 1; i <= m; i++)
            f>>b[i];
      for(i=1;i<=n;i++)
      {
            for(j=1;j<=m;j++)
            {
                  if(a[i]==b[j])c[i][j]=c[i-1][j-1]+1;
                  else c[i][j]= max(c[i][j-1],c[i-1][j]);
            }
      }
      g<<c[n][m]<<"\n";
      int l=c[n][m];
      int aux[1024];
      i=n;j=m;
      while(i && j){
      
                 if(a[i]==b[j]){
                       aux[--l]=a[i];
                       i--;
                       j--;
                       }
                 else{
                       if(c[i-1][j]<c[i][j-1])--j;
                       else --i;
                 }
            
      }
      for(i=0;i<c[n][m];i++)
            g<<aux[i]<<" ";
      f.close();
      g.close();
}