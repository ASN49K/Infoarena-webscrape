#include <fstream>
using namespace std;

int cmmdc(int c, int d)
{
  if((!c) || (!d)) return c+d;
  if(c>d) return cmmdc(c%d,d);
  return cmmdc(c,d%c);
}


int main() {
  int a,b;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>a;
  f>>b;
  //  cmmdc(a, b);
  if (cmmdc(a, b)==1) g<<0; else g<<cmmdc(a, b);
}
