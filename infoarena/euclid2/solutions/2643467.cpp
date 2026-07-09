#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

int cmmdc(int a , int b){
  if(a == 0 && b)
    return b;
  else if(b == 0 && a)
    return a;
  while(a != b){
    if(a > b)
      a = a - b;
    else
      b = b - a;
  }
  return a;
}

int main(){
  int n; f >> n;
  for(int i = 1; i <= n; i++){
    int x , y;
    f >> x >> y;
    g << cmmdc(x , y) << endl;
  }
}
