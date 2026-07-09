#include <fstream>
#include <iostream>
using namespace std;
ifstream ifs("cmlsc.in"); ofstream ofs("cmlsc.out");
int si[1025],sii[1025],D[1025][1025],cmlsc[1025],m,n,t,i,j;

int main() {
  ifs>>m>>n;
  for(i=1;i<=m;i++)
    ifs>>si[i];
  for(i=1;i<=n;i++)
    ifs>>sii[i];
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
      if(si[i]==sii[j])
        D[i][j]=D[i-1][j-1]+1;
      else
        D[i][j]=max(D[i-1][j],D[i][j-1]);
  ofs<<D[m][n]<<'\n';
  i=m; j=n;
  while (i && j){
    if(si[i]==sii[j]){
      cmlsc[t++]=si[i]; i--; j--;
    }
    else
      if(D[i-1][j]>D[i][j-1])
        i--;
      else
        j--;
  }
  for(i=t-1;i>-1;i--){
    ofs<<cmlsc[i]<<" ";
  }
}
