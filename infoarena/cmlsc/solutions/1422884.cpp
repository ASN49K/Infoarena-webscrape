#include <iostream>
#include <fstream>
using namespace std;
ifstream fi("cifre.txt");
ofstream fo("cifre.out");
int  a[1000],b[1000],y,i,n,m,j;
int main()
{fi>>n>>m;
for(i=1;i<=n;i++)
  fi>>a[i];
for(j=1;j<=m;j++)
  fi>>b[j];
  for(i=1;i<=n;i++){
    for(j=1;j<=m;j++)
      if(a[i]==b[j]){y=i;fo<<a[i]<<" ";break;}}


          return 0;
}
