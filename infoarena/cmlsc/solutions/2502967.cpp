#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream in("cmlsc.in");
ifstream out("cmlsc.out");

int v[1025][1025], a[1025], b[1025], sol[1025];
int n, m;

int main(){
  
  in>>n>>m;
  for(int i = 1; i <= n; i++){
    in>>a[i];
  }
  for(int i = 1; i <= m; i++){
    in>>b[i];
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= m; j++){
      if(a[i] == b[j])
        v[i][j] = v[i-1][j-1] + 1;
      else v[i][j] = max(v[i][j-1], v[i-1][j]);
    }
  }

  int count = v[n][m], k = m;

  for(int i = n; i >= 1; i--){
    for(int j = k; j >= 1; j--){
      if(a[i] == b[j] && v[i][j] == count){
        sol[count--] = a[i];
        k = j;
      }
    }
  }
  k = v[n][m];
  out<<k<<"\n";
  for(int i = 1; i <= k; i++){
    out<<sol[i]<<" ";
  }

  return 0;
}

