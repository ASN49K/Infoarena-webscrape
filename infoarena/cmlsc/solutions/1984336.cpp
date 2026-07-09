#include <iostream>
#include <fstream>

using namespace std;

ifstream in("cmlsc.in");
ofstream out("cmlsc.out");

int a[1024],b[1024],n,m;
int rez[1024],lg[1024],nr;

void citire(){
  in>>n>>m;
  for(int i=1;i<=n;i++){
    in>>a[i];
  }
  for(int i=1;i<=m;i++){
    in>>b[i];
  }
}

int maxim(int a, int b){
  if(a>b)
    return a;
  else
    return b;
}

void cmlsc(){
  lg[0] = 0;
  for(int i=1;i<=m;i++){
    for(int j=1;j<=n;j++){
      if(b[i] != a[j]){
        lg[i]=maxim(lg[i-1],lg[i]);
      }
      else{
        lg[i]=maxim(lg[i-1],lg[i])+1;
        rez[++nr]=b[i];
      }
    }
  }
  out<<nr<<'\n';
  for(int i=1;i<=nr;i++)
    out<<rez[i]<<' ';
}

int main(){
  citire();
  cmlsc();
  return 0;
}
