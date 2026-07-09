#include <iostream>
#include <fstream>
using namespace std;
int main()
{

ifstream A("euclid2.in");
ofstream B("euclid2.out");
int T,a,b,r;
A>>T;
for(int i=1;i<=T;++i)
    {
      A>>a>>b;
      r=a%b;
      while(r)
          {
            a=b;
            b=r;
            r=a%b;
          }
      B<<a<<'\n';
    }

return 0;
}
