#include <iostream>
#include <fstream>
using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long long cmmdc(unsigned long long a , unsigned long long b){
  unsigned long long c;
  while(b){
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main(){
  int n; f >> n;
  for(int i = 1; i <= n; i++){
    unsigned long long x , y;
    f >> x >> y;
    g << cmmdc(x , y) << '\n';
  }
}
