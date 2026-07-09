#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    int T,a,b;
    f>>T;
    while(T>0)
    {
     f>>a>>b;
      while(a!=b)
      {
        if(a>b)
        a=a-b;
         else
            b=b-a;
      }
      g<<a<<endl;
      T=T-1;
    }
    return 0;
}
