#include <fstream>
 
using namespace std;
 
int gcd(int x, int y){
  int z;
  while(y){
    z = x;
    x = y;
    y = z % y;
  }
  return x;
}
 
int main(){
  ifstream in("euclid2.in");
  ofstream out("euclid2.out");
 
  int t;
  in >> t;
 
  while(t--){
    int x, y;
    in >> x >> y;
    out << gcd(x, y) << "\n";
  }
 
  return 0;
}