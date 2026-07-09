#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){
  int a, b;
  in >> a >> b;

  int c;
  c = __gcd(a, b);

  out << c;
  return 0;
}
