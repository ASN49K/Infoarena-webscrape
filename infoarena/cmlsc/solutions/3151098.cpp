#include <iostream>
#include <fstream>
using namespace std;

ifstream f("cmlsc.in");
ofstream g("cmlsc.out");

int m, n, a[1025], b[1025], c;

int main() {
  f >> m >> n;
  for (int i = 0; i < m; i++) {
    f >> a[i];
  }
  for (int i = 0; i < n; i++) {
    f >> b[i];
  }
  int v[1025];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i] == b[j]) {
        if (c == 0) {
          v[c++] = j;
        }
        else {
          if (j > v[c - 1]) v[c++] = j;
        }
      }
    }
  }
  g << c << '\n';
  for (int i = 0; i < c; i++) {
    g << b[v[i]] << ' ';
  }
}