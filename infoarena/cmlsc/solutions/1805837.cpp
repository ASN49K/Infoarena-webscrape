#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");


int a[1024],b[1024],mat[1024][1024],m,n,i,j,sir[1024],nr;
int main()
{
    f>>n>>m;
    nr=0;
    for (i=1;i<=n;i++)
     f>>a[i];
    for(j=1;j<=m;j++)
        f>>b[j];
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){
    if(a[i]==b[j])
        mat[i][j]=1+mat[i-1][j-1];
    else
        mat[i][j]=max(mat[i-1][j],mat[i][j-1]);
        }
        g<<mat[n][m]<<endl;
      for(i=n;i>=1;i--)
      for(j=m;j>=1;j--){
      if(a[i]==b[j]){
        sir[++nr]=a[i];
        i--;
        j--;
      }
      else if(mat[i-1][j]<mat[i][j-1])
       j--;
       else
        i--;
      }
       for(i=nr;i>=1;i--)
        g<<sir[i]<<" ";
    return 0;
}
