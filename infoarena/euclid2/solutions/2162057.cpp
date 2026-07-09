#include <iostream>
#include <fstream>
using namespace std;

int cmmdc(int a,int b){
  int r;
  while (b!=0){
  r=a%b;
  a=b;
  b=r;
     }
  return a;
  }

int main(){
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int a,b,n;
  f>>n;
  for(int i=0;i<n;i++){
     f>>a>>b;
     g<<cmmdc(a,b)<<endl;
     }
  return 0;
 }
