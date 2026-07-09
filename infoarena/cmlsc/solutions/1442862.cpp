#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
ifstream fi("cmlsc.in");
ofstream fo("cmlsc.out");
int n,m,i,j,l,c,aux,k;
int s1[1025],s2[1025],a[1025][1025],lsol,lsol2,sol[1025];
//string s1;
//string s2;
int main(){
  fi >> n >> m;
  for(i=1;i<=n;i++) fi >> s1[i];
  for(i=1;i<=m;i++) fi >> s2[i];
  /*
  fi >> s1 >> s2;
  s1 = ' ' + s1;
  s2 = ' ' + s2;
  n = s1.size()-1;
  m = s2.size()-1;
  */
  for(l=1;l<=n;l++)
  for(c=1;c<=m;c++){
    if(s1[l] == s2[c])
        a[l][c] = a[l-1][c-1] + 1;
    else a[l][c] = max(a[l-1][c],a[l][c-1]);
  }
  /*
  for(l=1;l<=n;l++){
  for(c=1;c<=m;c++)
    cout << a[l][c] << ' ';
  cout << endl;
  }
  cout << endl;
  */
  lsol = lsol2 = a[n][m];
  l = n; c = m;
  while(lsol){
    if(a[l][c] == a[l-1][c]) l--;
    else if(a[l][c] == a[l][c-1]) c--;
    else {
      sol[lsol--] = s1[l];
      l--; c--;
    }
  }
  fo << lsol2 << endl;
  for(i=1;i<=lsol2;i++) fo << sol[i] << ' ';
  return 0;
}
