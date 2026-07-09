#include<fstream>
using namespace std;
int main()
{ ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  long a, b, r, t;
  f>>t;
  while(t!=0)
  {
    f>>a>>b;
      while(b!=0)
      {
        r=a%b;
        a=b;
        b=r;
      }
      g<<a;
  }
  return 0;
}
