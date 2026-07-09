#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int T,a,b;

    ifstream f("euclid2.in");
    ofstream g("euclid2.out");
    f>>T;
    while(T) {
      f >> a >> b;
      while(a != b) {
         if(a>b) a-=b;
         else b-=a; }
      g << b << '\n';
      T--;
    }

}
