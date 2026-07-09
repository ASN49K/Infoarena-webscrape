#include <iostream>
#include <fstream>
using namespace std;
ifstream in("euclid2.in");
ofstream out("euclid2.out");
int main()
{
  unsigned int r, a, b,n;
  in>>n;
  for(unsigned int i=0;i<n; ++i)
  {
    in>>a>>b;
    r = a%b;
    while(r)
    {
      a = b;
      b = r;
      r = a%b;
    }
    out<<b<<'\n';
  }

}
