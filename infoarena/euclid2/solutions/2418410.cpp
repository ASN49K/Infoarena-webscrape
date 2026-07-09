#include <fstream>

using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int T,a,b;
int euclid(int x, int y){
  while (y!=0) {
    int r = x % y;
    x = y;
    y = r;
  }
  return x;
}
int main() {
  in>>T;
  for(int i = 0; i < T; ++i){
    in>>a>>b;
    out<<euclid(a,b)<<'\n';
  }
  return 0;
}
