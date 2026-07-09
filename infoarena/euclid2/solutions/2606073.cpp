#include <iostream>
#include <fstream>
using namespace std;
int main(){
  long long  T , a , b ,rest;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f >> T;
  for ( int i = 0; i < T; i++){
    f >> a >> b;
      while (b != 0){
        rest =  a % b;
        a = b;
        b = rest;
      }
      g << a << "\n";
    }
    f.close();
    g.close();
  return 0;
}
