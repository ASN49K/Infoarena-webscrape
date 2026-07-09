#include <iostream>
#include <fstream>

using namespace std;

ifstream in("nim.in");
ofstream out("nim.out");

int main() {

  int t;
  in >> t;
  for(int q = 1;q <= t;q++) {
    int n, ans = 0;
    in >> n;
    for(int i = 1;i <= n;i++) {
      int c;
      in >> c;
      ans ^= c;
    }
    if(ans == 0) {
      out << "NU\n";
    }else {
      out << "DA\n";
    }
  }
  out << '\n';
  return 0;
}
