#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    unsigned int T,a,b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    while(T) {
      f >> a >> b;
      if(a == 0) g << b << '\n';
      if(b == 0) g << a << '\n';
      while(a != b) {
         if(a>b) a-=b;
         else b-=a; }
      g << b << '\n';
      T--;
    }

}
