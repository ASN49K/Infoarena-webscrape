#include <iostream>
#include <fstream>
using namespace std;
int GCD(int a , int b){
  if (!b)
    return a;
  return GCD(b,a%b);
}
int main(){
  long long  T , a , b ,rest;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f >> T;
  for ( int i = 0; i < T; i++){
    f >> a >> b;
      g << GCD( a , b ) << "\n";
    }
    f.close();
    g.close();
  return 0;
}
