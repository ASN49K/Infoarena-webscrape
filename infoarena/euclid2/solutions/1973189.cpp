#include <iostream>
#include <fstream>
using namespace std;
int a,b,T,i=0,t;
int main()
{
  ifstream f("euclid2.in");
  ofstream  g("euclid2.out");
  f>>T;
  while(i<T)
  {
      f>>a>>b;
      while(b!=0)
      {
          t=b;
          b=a%b;
          a=t;
      }
      g<<a<<"\n";
      i++;
  }
}
