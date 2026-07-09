#include <fstream>
#include <iostream>
using namespace std;
ifstream fin("cmlsc.in"); ofstream fout("cmlsc.out");
int a[1025], b[1025],D[1025][1025],cmlsc[1025],m,n,t,i,j;

int main() {
  fin>>m>>n;
  for(i=1;i<=m;i++)
    fin>>a[i];
  for(i=1;i<=n;i++)
    fin>>b[i];
  for(i=1;i<=m;i++)
    for(j=1;j<=n;j++)
      if(a[i]==b[j])
        D[i][j]=D[i-1][j-1]+1;
      else
        D[i][j]=max(D[i-1][j],D[i][j-1]);
  fout<<D[m][n]<<'\n';
  i=m; j=n;
  while (i && j){
    if(a[i]==b[j]){
      cmlsc[t++]=a[i];
      i--;
      j--;
    }
    else
      if(D[i-1][j]>D[i][j-1])
        i--;
      else
        j--;
  }
  for(i=t-1;i>-1;i--)
    fout<<cmlsc[i]<<" ";
}
