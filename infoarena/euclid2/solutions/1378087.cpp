#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream f;
ofstream g;
int main()
{ f.open("euclid2.in");
g.open("euclid2.out");
  int T,a,b,i;
  f>>T;
  for(i=1;i<=T;i++)
  {f>>a>>b;
  g<<__gcd(a,b)<<endl;}
  f.close();
  g.close();
    return 0;
}
