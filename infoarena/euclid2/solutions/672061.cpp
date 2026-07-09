#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>

using namespace std;

istream* in = &cin;
ostream* out = &cout;

int gcd (int a, int b)
{
  if (a == 0)
  {
    return b;
  }
  if ( b == 0)
  {
    return a;
  }
  if (a > b)
  {
    return gcd (a - b, b); 
  }
  else
  {
    return gcd (a, b - a);
  }
}

int main ()
{
  int testCount = 0; 
  ifstream inf("euclid2.in");  
  ofstream of("euclid2.out");
  in = &inf;
  out = &of;
  (*in) >> testCount;
  for (int i = 0; i < testCount; i++)
  {
    int a;
    int b;
    (*in) >> a >> b;
    (*out) << gcd (a, b) << endl;
  }
  return 0;
}
