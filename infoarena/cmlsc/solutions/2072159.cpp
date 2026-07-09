#include <iostream>
#include <fstream>
using namespace std;
ifstream f("cmlsc.in");
ofstream g("cmlsc.out");
int m[1025][1025],i,j,_a,_b,a[1025],b[1025],c[1025],x;
int main()
{
  f>>_a>>_b;
  for(i=1;i<=_a;i++) f>>a[i];
  for(i=1;i<=_b;i++) f>>b[i];
  for(i=0;i<=1024;i++) m[i][0]=m[0][i]=0;
  for(i=1;i<=_a;i++)
    for(j=1;j<=_b;j++)
  {
      if(a[i]==b[j]) m[i][j]=1+m[i-1][j-1];
      else m[i][j]=max(m[i-1][j],m[i][j-1]);
  }
  g<<m[_a][_b]<<'\n';
  x=m[_a][_b];
  i=_a;j=_b;
  while(m[_a][_b])
  {
      if(m[i-1][j]==m[i][j]) i--;
      else if(m[i][j-1]==m[i][j]) j--;
      else {
        c[m[_a][_b]]=a[i];
        i--;j--;m[_a][_b]--;
      }
  }
  for(i=1;i<=x;i++)
    g<<c[i]<<" ";
}
