#include <bits/stdc++.h>

using namespace std;

ifstream in("euclid2.in");
ofstream out("euclid2.out");

int main(){
  int n;
  in >> n;
  for (int i = 1; i <= t; ++ i){
    int a, b;
    in >> a >> b;

    int c;
    c = __gcd(a, b);

    out << c;

  }
  return 0;
}
