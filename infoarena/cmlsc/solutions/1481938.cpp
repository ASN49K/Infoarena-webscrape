#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

 int v1[1024],v2[1024],a[1025][1025],m,n,i,j,b[1024],k=1;

void print(int x, int y)
{  if(a[x][y]!=0)
    {if(v1[x]==v2[y]){b[k]=v1[x];k++;print(x-1,y-1);}
       else if(a[x-1][y]==a[x][y])print(x-1,y);
                 else print(x,y-1);}
}
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
      for( j=1;j<=n;j++){if(v1[i]==v2[j])a[i][j]=1+a[i-1][j-1];
                           else {if(a[i-1][j]>a[i][j-1])a[i][j]=a[i-1][j];
                                      else a[i][j]=a[i][j-1];}}
   g<<a[m][n]<<endl;
   print(m,n);
   for(i=k-1;i>0;i--)g<<b[i]<<" ";
    g.close();
    f.close();
}
