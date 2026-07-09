// #include <iostream>
// #include <fstream>
// #include <algorithm>
// #include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b) {
  if (a > b)
    return gcd (b, a);
  else if (a == 0)
    return b;
  else return gcd(b%a, a);
}

int main() {

  ifstream fin ("euclid2.in");
  ofstream fout ("euclid2.out");

  int T, a, b;
  fin >> T;

  for (int i = 0; i < T; i++) {
    fin >> a >> b;
    fout << gcd(a, b) << "\n";
  }

  return 0;
};


