#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

 int v1[1024],v2[1024],a[1025][1025],m,n,i,j,b[1024],k=1;


 void read()
 {
    f>>m>>n;
    for( i=1;i<=m;i++)f>>v1[i];
    for( i=1;i<=n;i++)f>>v2[i];
    for( i=0;i<=m;i++)a[i][0]=0;
      for( i=0;i<=n;i++)a[0][i]=0;
 }

int main()
{
      read();

      for( i=1;i<=m;i++)
      for( j=1;j<=n;j++){if(v1[i]==v2[j]){a[i][j]=1+a[i-1][j-1]; if(b[k-1]!=v1[i]){b[k]=v1[i]; k++;}}
                           else {if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
                                      else a[i][j]=a[i][j-1];}}
   g<<a[m][n]<<endl;

      for( i=1;i<=k-1;i++)g<<b[i]<< " ";


    g.close();
    f.close();
}
