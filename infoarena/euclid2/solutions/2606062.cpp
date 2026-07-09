#include <iostream>
#include <fstream>
using namespace std;
int main(){
  int T , a , b , d;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f >> T;
  for ( int i = 0; i < T; i++){
    f >> a >> b;
      while ( a != b){
        if (a > b )
          a = a - b;
        if (b > a)
          b = b - a;
      }
      d = a;
      cout << d << "\n";
    }
  return 0;
}
