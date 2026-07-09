#include <iostream>
#include <fstream>

using namespace std;

int  gcd(int  a , int b)
{
    if (b==0) {return a;}
    return gcd(b,a%b);
}


int main()
{

  ifstream f("euclid2.in");
  ofstream g("euclid2.out");
  int t;
  int x;
  int y;
  f>>t;

for ( int i=1; i<= t; i++)
  {
f>>x>>y;
     g << gcd(x,y) << endl;
}
}
