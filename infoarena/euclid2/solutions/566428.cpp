#include <iostream>
#include <fstream>

using namespace std;

ifstream f("euclid2.in");
ofstream g("euclid2.out");

unsigned long long a,b,t,i;

unsigned long long cmmdc(unsigned long long x,unsigned long long y) {
  unsigned long long r;
  while (y!=0) {
    r=y;
    y=x%y;
    x=r;
  }
  return x;
}
int main () {
  f >> t;
  for (i=1;i<=t;i++) {
    f >> a >> b;
    g << cmmdc(a,b) << '\n';
  }
  f.close();g.close();
  return 0;
}
