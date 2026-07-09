#include<iostream>
#include<fstream>
using namespace std;
unsigned euclid( unsigned a, unsigned b)
{
    unsigned r=a%b;
    while(r)
    {
        a=b;
        b=r;
        r=a%b;
    }
    return b;
}

int main()
{
    unsigned n,a,b;
  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  f>>n;
  for(int i=0;i<n;i++)
  {
      f>>a;
      f>>b;
      g<<euclid(a,b)<<endl;
  }
}
