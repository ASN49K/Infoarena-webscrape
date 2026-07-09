#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b,rest;
    f>>T;
    for(int i=1;i<=T;i++)
    {
          f>>a>>b;
      while(b!=0)
      {
        rest=a%b;
        a=b;
        b=rest;
      }
       g<<a<<"\n";
    }
    return 0;
}
