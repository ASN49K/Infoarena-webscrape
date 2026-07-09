#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("cmlsc.in");
ofstream fout("cmlsc.out");

int n,m,x,i,j,a[1025],b[1025],D[1025][1025],c[1025];

int main(){
  fin>>n>>m;
  for(i=1;i<=n;++i)
    fin>>a[i];
  for(j=1;j<=m;++j)
    fin>>b[j];
  for(i=1;i<=n;++i){
    for(j=1;j<=m;++j){
      if(a[i]==b[j])
        D[i][j]=D[i-1][j-1]+1;
      else
        D[i][j]=max(D[i-1][j],D[i][j-1]);
    }
  }
  fout<<D[n][m]<<'\n';
  while(i && j){
    if(a[i]==b[j]){
      c[++x]=a[i];
      i--;
      j--;
    }
    else if(D[i-1][j]<D[i][j-1]) j--;
    else i--;
  }
  for(i=x;i>1;--i)
    fout<<c[i]<<' ';
	return 0;
}

